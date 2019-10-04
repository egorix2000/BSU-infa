#include "Dlg.h"

const int MAX_STRING_LENGTH = 100;

INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	TCHAR value[MAX_STRING_LENGTH];
	static Model<int>* model;
	static View<int>* view;

	switch (message) {
	case WM_INITDIALOG: {
		view = new View<int>;
		view->set_view(hDlg);
		model = new Model<int>;
		model->set_view(view);
		break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_PUSH_BACK_BUTTON: {
			GetDlgItemText(hDlg, ID_PUSH_EDIT, value, MAX_STRING_LENGTH);
			model->pushBack(atoi(value));
			break;
		}
		case ID_PUSH_FRONT_BUTTON: {
			GetDlgItemText(hDlg, ID_PUSH_EDIT, value, MAX_STRING_LENGTH);
			model->pushFront(atoi(value));
			break;
		}
		case ID_POP_BACK_BUTTON: {
			model->popBack();
			break;
		}
		case ID_POP_FRONT_BUTTON: {
			model->popFront();
			break;
		}
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hDlg);
		break;
	case WM_DESTROY:
		delete view;
		delete model;
		PostQuitMessage(0);
		return TRUE;
		break;
	}
	return FALSE;
}