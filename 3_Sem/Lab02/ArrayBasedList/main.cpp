﻿#include <windows.h>
#include "Dlg.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	if (!InitInstance(hInstance, nCmdShow)) return (FALSE);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}