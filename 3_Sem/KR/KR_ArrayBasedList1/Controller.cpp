#include "Controller.h"

const int MAX_STRING_LENGTH = 100;

INT_PTR CALLBACK Controller(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
	TCHAR valueRe[MAX_STRING_LENGTH];
	TCHAR valueIm[MAX_STRING_LENGTH];
	static Model<ComplexNumber>* model;
	static View<ComplexNumber>* view;

	switch (message) {
	case WM_INITDIALOG: {
		view = new View<ComplexNumber>;
		view->set_view(hDlg);
		model = new Model<ComplexNumber>;
		model->set_view(view);
		break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case ID_PUSH_BACK_BUTTON: {
			GetDlgItemText(hDlg, ID_RE_PUSH_EDIT, valueRe, MAX_STRING_LENGTH);
			GetDlgItemText(hDlg, ID_IM_PUSH_EDIT, valueIm, MAX_STRING_LENGTH);
			model->pushBack(ComplexNumber(atof(valueRe), atof(valueIm)));
			break;
		}
		case ID_PUSH_FRONT_BUTTON: {
			GetDlgItemText(hDlg, ID_RE_PUSH_EDIT, valueRe, MAX_STRING_LENGTH);
			GetDlgItemText(hDlg, ID_IM_PUSH_EDIT, valueIm, MAX_STRING_LENGTH);
			model->pushFront(ComplexNumber(atof(valueRe), atof(valueIm)));
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