#undef UNICODE
#include <windows.h>
#include <string>
#include "KWnd.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 3", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	static HDC hDC;
	static int x, y;
	static BOOL bTracking = FALSE;
	switch (uMsg) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		break;
	case WM_LBUTTONDOWN: 
		bTracking = TRUE;
		x = LOWORD(lParam);
		y = HIWORD(lParam); 
		MoveToEx(hDC, x, y, NULL); 
		break;
	case WM_LBUTTONUP:
		bTracking = FALSE;
		break;
	case WM_MOUSEMOVE: 
		if (bTracking) {
			x = LOWORD(lParam); 
			y = HIWORD(lParam); 
			LineTo(hDC, x, y);
		}
		break;
	case WM_DESTROY: 
		ReleaseDC(hWnd, hDC); 
		PostQuitMessage(0); break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
