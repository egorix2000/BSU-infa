#include "Dlg.h"

const int MAX_STRING_LENGTH = 100;

List listA, listB;

void updateList(HWND& hDlg, std::ostringstream& stream, List& list, int id) {
	stream.str("");
	stream.clear();
	stream << list;
	SetDlgItemText(hDlg, id, stream.str().c_str());
}

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	TCHAR value[MAX_STRING_LENGTH];
	std::ostringstream ostream;
	std::istringstream istream;
	IsEmptyVisitor visitor;
	switch (message) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_SWAP:
			swap(listA, listB);
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			updateList(hDlg, ostream, listB, ID_LIST_B_ELEMENTS);
			break;
		case ID_EMPTY_BUTTON:
			listA.accept(visitor);
			if (visitor.value) {
				SetDlgItemText(hDlg, ID_EMPTY_TEXT, "True");
			}
			else {
				SetDlgItemText(hDlg, ID_EMPTY_TEXT, "False");
			}
			break;
		case ID_SIZE_BUTTON:
			SetDlgItemText(hDlg, ID_SIZE_TEXT, std::to_string(listA.size()).c_str());
			break;
		case ID_EQUAL_BUTTON:
			if (listA == listB) {
				SetDlgItemText(hDlg, ID_EQUAL_TEXT, "True");
			}
			else {
				SetDlgItemText(hDlg, ID_EQUAL_TEXT, "False");
			}
			break;
		case ID_NOT_EQUAL_BUTTON:
			if (listA != listB) {
				SetDlgItemText(hDlg, ID_NOT_EQUAL_TEXT, "True");
			}
			else {
				SetDlgItemText(hDlg, ID_NOT_EQUAL_TEXT, "False");
			}
			break;
		case ID_BACK_BUTTON:
			SetDlgItemText(hDlg, ID_BACK_TEXT, std::to_string(listA.back()).c_str());
			break;
		case ID_FRONT_BUTTON:
			SetDlgItemText(hDlg, ID_FRONT_TEXT, std::to_string(listA.front()).c_str());
			break;
		case ID_ADD_BUTTON:
			ostream.str("");
			ostream.clear();
			ostream << listA + listB;
			SetDlgItemText(hDlg, ID_ADD_TEXT, ostream.str().c_str());
			break;
		case ID_PUSH_BACK_BUTTON:
			GetDlgItemText(hDlg, ID_PUSH_EDIT, value, MAX_STRING_LENGTH);
			listA.pushBack(atoi(value));
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_PUSH_FRONT_BUTTON:
			GetDlgItemText(hDlg, ID_PUSH_EDIT, value, MAX_STRING_LENGTH);
			listA.pushFront(atoi(value));
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_POP_BACK_BUTTON:
			listA.popBack();
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_POP_FRONT_BUTTON:
			listA.popFront();
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_ASSIGNMENT_BUTTON:
			listA = listB;
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_ADD_ASSIGNMENT_BUTTON:
			listA += listB;
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_CLEAR:
			listA.clear();
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_CHANGE_A_BUTTON:
			GetDlgItemText(hDlg, ID_CHANGE_A_EDIT, value, MAX_STRING_LENGTH);
			istream.str(value);
			istream >> listA;
			updateList(hDlg, ostream, listA, ID_LIST_A_ELEMENTS);
			break;
		case ID_CHANGE_B_BUTTON:
			GetDlgItemText(hDlg, ID_CHANGE_B_EDIT, value, MAX_STRING_LENGTH);
			istream.str(value);
			istream >> listB;
			updateList(hDlg, ostream, listB, ID_LIST_B_ELEMENTS);
			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hDlg);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return TRUE;
		break;
	}
	return FALSE;
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	HWND hDlg = CreateDialogParam(hInstance,
		MAKEINTRESOURCE(IDD_DIALOG1),
		0,
		DlgProc,
		0);
	if (!hDlg) return (FALSE);
	ShowWindow(hDlg, nCmdShow);
	UpdateWindow(hDlg);
	return (TRUE);
}