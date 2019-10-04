#include <windows.h>
#include "Dlg.h"

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
	HWND hDlg = CreateDialogParam(hInstance,
		MAKEINTRESOURCE(IDD_DIALOG1),
		0,
		Controller,
		0);
	if (!hDlg) return (FALSE);
	ShowWindow(hDlg, nCmdShow);
	UpdateWindow(hDlg);
	return (TRUE);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	if (!InitInstance(hInstance, nCmdShow)) return (FALSE);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

