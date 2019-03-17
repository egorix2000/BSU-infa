#undef UNICODE
#include <windows.h>
#include <cmath>
#include "KWnd.h"

#define ID_EDITCHILD 100

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 2_1", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;

	static HWND hWndEdit;
	static LOGFONT lf;
	HFONT hFont;
	RECT clientRect;
	RECT equationRect;
	RECT intervalRect;

	switch (message) {
	case WM_CREATE:
		hWndEdit = CreateWindowEx(0, "EDIT", NULL, WS_CHILD | WS_VISIBLE | WS_BORDER,
			0, 0, 0, 0, hWnd, (HMENU)ID_EDITCHILD, (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE), NULL);
		break;
	case WM_SIZE:
		MoveWindow(hWndEdit,
			5, 0,
			LOWORD(lParam) - 5,
			HIWORD(lParam) / 10,
			TRUE);
		lf.lfHeight = HIWORD(lParam) / 15;
		hFont = CreateFontIndirect(&lf);
		SendMessage(hWnd, WM_SETFONT, WPARAM(hFont), TRUE);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		SetBkMode(hDC, TRANSPARENT);
		GetClientRect(hWnd, &clientRect);

		SetRect(&equationRect, 5, 0, clientRect.right - 5, clientRect.bottom / 10);
		SetRect(&intervalRect, 5, clientRect.bottom / 10, clientRect.right - 5, 2 * clientRect.bottom / 10);

		//SelectObject(hDC, hFont);

		//DrawText(hDC, "equation", -1, &equationRect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);
		
		//DrawText(hDC, "interval", -1, &intervalRect, DT_SINGLELINE | DT_LEFT | DT_VCENTER);

		DeleteObject(SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT)));
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
