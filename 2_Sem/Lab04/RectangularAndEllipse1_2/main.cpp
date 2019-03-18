#undef UNICODE
#include <windows.h>
#include "KWnd.h"
#include "style.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 1_2", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC;
	RECT clientRect;
	RECT rectangleRect;
	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		SetRect(&rectangleRect, clientRect.left + MARGIN_TEN_PX, clientRect.top + MARGIN_TEN_PX, 
			clientRect.right - MARGIN_TEN_PX, clientRect.bottom - MARGIN_TEN_PX);

		FillRect(hDC, &rectangleRect, (HBRUSH)GetStockObject(BLACK_BRUSH));
		Ellipse(hDC, clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);
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
