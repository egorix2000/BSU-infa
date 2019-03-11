#undef UNICODE
#include <windows.h>
#include "KWnd.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 1_3", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC; 
	PAINTSTRUCT ps; 
	RECT rect;
	LPCSTR helloWorld = "Hello, World!";

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &rect);
		SetBkMode(hDC, TRANSPARENT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_BOTTOM | DT_RIGHT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_BOTTOM | DT_LEFT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_TOP | DT_RIGHT);
		DrawText(hDC, helloWorld, -1, &rect, DT_SINGLELINE | DT_TOP | DT_LEFT);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
