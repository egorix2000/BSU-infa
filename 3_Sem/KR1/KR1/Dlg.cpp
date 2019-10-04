#include "Dlg.h"

const int MAX_STRING_LENGTH = 100;

List<int> listA, listB;

void updateList(HWND& hDlg, std::ostringstream& stream, List<int>& list, int id) {
	stream.str("");
	stream.clear();
	stream << list;
	SetDlgItemText(hDlg, id, stream.str().c_str());
}

INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	TCHAR value[MAX_STRING_LENGTH];
	std::ostringstream ostream;
	std::istringstream istream;
	switch (message) {
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
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