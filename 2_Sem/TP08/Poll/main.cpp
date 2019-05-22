#include <windows.h>
#include <string>
#include <cstring>
#include <commdlg.h>
#include <numeric>
#include <iostream>
#include "tchar.h"
#include "answerform.h"
#include "pollfactory.h"
#include "resource.h"
#include "poll.h"
#include "KWnd.h"

const char* text = "Press enter to start poll";

OPENFILENAME file;
char szFile[260];

int current_id = 0;
int radio_ids[] = { IDC_RADIO1, IDC_RADIO2, IDC_RADIO3, IDC_RADIO4, IDC_RADIO5 };
int check_ids[] = { IDC_CHECK1, IDC_CHECK2, IDC_CHECK3, IDC_CHECK4, IDC_CHECK5 };
Poll poll;
AnswerForm answerForm;

INT_PTR CALLBACK DlgProc(HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

BOOL InitApplication(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow);
void draw(HWND& hwnd);
void drawText(HDC& hdc, RECT wRect);
void addAnswers(HWND& hdlg);
void initDialog(HWND& hdlg);
void finalMessageBox(HWND& hwnd);
void writeAnswersInStream(std::ostream& out, double res, double totalPoints);
INT_PTR questionDialogBox(HWND& hdlgCurrent);
INT_PTR nextQuestionDialogBox(HWND& hdlgCurrent);
INT_PTR prevQuestionDialogBox(HWND& hdlgCurrent);
void onEnterPressed(HWND& hwnd, WPARAM wParam, LPARAM lParam);
INT_PTR endPoll(HWND hdlg);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	KWnd mainWnd("Window 1", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

INT_PTR CALLBACK DlgProc(HWND hdlg, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_INITDIALOG: {
		initDialog(hdlg);
		break;
	}
	case WM_COMMAND: {
		switch (LOWORD(wParam)) {
		case ID_NEXT_BUTTON: {
			addAnswers(hdlg);
			return nextQuestionDialogBox(hdlg);
			break;
		}
		case ID_PREV_BUTTON: {
			addAnswers(hdlg);
			return prevQuestionDialogBox(hdlg);
			break;
		}
		case ID_END_BUTTON: {
			return endPoll(hdlg);
			break;
		}
		}
		break;
	}
	}
	return FALSE;
}

INT_PTR endPoll(HWND hdlg) {
	int result = MessageBox(NULL, "Are you sure you wanr to end poll?", "Confirm", MB_YESNO);

	switch (result) {
	case IDYES:
		addAnswers(hdlg);
		HWND prnt = GetParent(hdlg);
		INT_PTR res = EndDialog(hdlg, 0);
		finalMessageBox(prnt);
		return res;
		break;
	}
	return 0;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message) {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_PAINT: {
		draw(hwnd);
		break;
	}
	case WM_KEYDOWN:
		if (wParam == 13) {
			onEnterPressed(hwnd, wParam, lParam);
		}
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

void initDialog(HWND& hdlg) {
	SetDlgItemText(hdlg, ID_QUESTION,
		_T(poll.questions[current_id].text.c_str()));
	bool isRadio = (poll.questions[current_id].type ==
		QuestionType::OneAnswer);
	int* ids = (isRadio) ? radio_ids : check_ids;
	for (int i = 0; i < 5; i++) {
		if (i < poll.questions[current_id].answers.size()) {
			SetDlgItemText(hdlg, ids[i],
				_T(
					poll.questions[current_id].answers[i].statement.c_str()
				));
			CheckDlgButton(hdlg, ids[i],
				answerForm.getCheckState(current_id, i));
		}
		else {
			ShowWindow(GetDlgItem(hdlg, ids[i]), SW_HIDE);
		}
	}
	if (current_id == 0) {
		EnableWindow(GetDlgItem(hdlg, ID_PREV_BUTTON), FALSE);
	}
	else if (current_id == poll.questions.size() - 1) {
		EnableWindow(GetDlgItem(hdlg, ID_NEXT_BUTTON), FALSE);
	}
}

INT_PTR nextQuestionDialogBox(HWND& hdlgCurrent) {
	INT_PTR result = FALSE;
	if (current_id == 0) {
		EnableWindow(GetDlgItem(hdlgCurrent, ID_PREV_BUTTON), TRUE);
	}
	current_id++;
	if (current_id < poll.questions.size()) {
		result = questionDialogBox(hdlgCurrent);
	}
	return result;
}

INT_PTR prevQuestionDialogBox(HWND& hdlgCurrent) {
	INT_PTR result = FALSE;
	if (current_id == poll.questions.size() - 1) {
		EnableWindow(GetDlgItem(hdlgCurrent, ID_NEXT_BUTTON), TRUE);
	}
	current_id--;
	if (current_id >= 0) {
		result = questionDialogBox(hdlgCurrent);
	}
	return result;
}

INT_PTR questionDialogBox(HWND& hdlgCurrent) {
	INT_PTR res = EndDialog(hdlgCurrent, 0);
	if (poll.questions[current_id].type ==
		QuestionType::OneAnswer) {
		DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1),
			GetParent(hdlgCurrent), DlgProc);
	}
	else {
		DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG2),
			GetParent(hdlgCurrent), DlgProc);
	}
	return res;
}

void addAnswers(HWND& hdlg) {
	bool isRadio = (poll.questions[current_id].type ==
		QuestionType::OneAnswer);
	int* ids = (isRadio) ? radio_ids : check_ids;
	for (int j = 0; j < poll.questions[current_id].answers.size(); j++) {
		answerForm.addAnswer(current_id, j,
			IsDlgButtonChecked(hdlg, ids[j]));
	}
}

void onEnterPressed(HWND& hwnd, WPARAM wParam, LPARAM lParam) {
	file.lStructSize = sizeof(OPENFILENAME);
	file.lpstrFilter = _T("Text\0*.txt");
	file.lpstrFile = szFile;
	file.nMaxFile = 256;
	file.lpstrTitle = NULL;
	file.hwndOwner = hwnd;
	file.Flags = OFN_HIDEREADONLY | OFN_FILEMUSTEXIST;
	file.lpstrInitialDir = _T(".\\");
	file.lpstrDefExt = _T("txt");
	if (GetOpenFileName(&file) == TRUE &&
		PollFactory::InitPoll(poll, std::string(file.lpstrFile))) {
		answerForm = AnswerForm(poll.questions.size());
		current_id = 0;
		if (poll.questions[current_id].type == QuestionType::OneAnswer) {
			DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, DlgProc);
		}
		else {
			DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG2), hwnd, DlgProc);
		}
	}
	else {
		MessageBox(hwnd,
			_T("Invalid file!"),
			_T("Error"),
			MB_OK | MB_ICONERROR);
		SendMessage(hwnd, WM_LBUTTONDOWN, wParam, lParam);
	}
}

void writeAnswersInStream(std::ostream & out, double res, double totalPoints) {	
	out << "Poll: " << poll.header << "\n";
	out << "Result: " << (int)res << " from " << (int)totalPoints << "\n";
	for (int i = 0; i < poll.questions.size(); i++) {
		out << "Question #" << (i + 1) << ": " << poll.questions[i].text << '\n';
		out << "Your Answer:";
		for (int j = 0; j < poll.questions[i].answers.size(); j++) {
			if (answerForm.getCheckState(i, j)) {
				out << "   " << poll.questions[i].answers[j].statement;
			}
		}
		out << "\n";
		out << "Correct Answer:";
		for (int j = 0; j < poll.questions[i].answers.size(); j++) {
			if (poll.questions[i].answers[j].correct) {
				out << "   " << poll.questions[i].answers[j].statement;
			}
		}
		out << "\n\n";
	}
}

void finalMessageBox(HWND & hwnd) {
	double totalPoints = 0;
	for (int i = 0; i < poll.questions.size(); i++) {
		totalPoints += poll.questions[i].points;
	}
	double res = answerForm.getResult(poll);
	std::string text = "Poll ended. Your result is "
		+ std::to_string((int) res) + " from " + std::to_string((int) totalPoints) + 
		". Do you want to save your result as text file?";
	int msgboxID = MessageBox(hwnd,
		_T(text.c_str()),
		_T("Poll result"),
		MB_YESNO | MB_ICONINFORMATION);
	switch (msgboxID) {
	case IDYES:
		file.lpstrTitle = _T("Îòêðûòü ôàéë äëÿ çàïèñè");
		file.Flags = OFN_NOTESTFILECREATE;
		if (GetSaveFileName(&file)) {
			std::ofstream fout;
			fout.open(szFile);
			writeAnswersInStream(fout, res, totalPoints);
			fout.close();
		}
		else {
			MessageBox(hwnd,
				_T("Error while saving your results"),
				_T("Error"),
				MB_OK | MB_ICONERROR);
		}
		break;
	}
}
void drawText(HDC & hdc, RECT wRect) {
	SIZE tSize;
	GetTextExtentPoint32(hdc, text, _tcslen(text), &tSize);
	int wWidth = wRect.right - wRect.left;
	int wHeight = wRect.bottom - wRect.top;
	int t_x = (wWidth - tSize.cx) / 2;
	int t_y = (wHeight - tSize.cy) / 2;
	TextOut(hdc, t_x, t_y, text, _tcslen(text));
}
void draw(HWND & hwnd) {
	PAINTSTRUCT ps;
	RECT rect;
	GetClientRect(hwnd, &rect);
	HDC hDc = BeginPaint(hwnd, &ps);
	drawText(hDc, rect);
	EndPaint(hwnd, &ps);
}

