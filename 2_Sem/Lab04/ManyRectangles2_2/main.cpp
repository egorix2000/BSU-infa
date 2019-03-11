#undef UNICODE
#include <windows.h>
#include <cmath>
#include <ctime>
#include "KWnd.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	srand(time(NULL));
	MSG msg;
	
	KWnd mainWnd("Window 2_2", hInstance, nCmdShow, WndProc);

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
	INT n = 20;
	COLORREF startColor;
	RECT clientRect;
	RECT currentRect;

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &clientRect);
		startColor = RGB(rand() % 255, rand() % 255, rand() % 255);

		SetRect(&currentRect, clientRect.left, clientRect.top, clientRect.right, clientRect.bottom);
		
		for (INT i = 0; i < n; i++) {
			SelectObject(hDC, CreateSolidBrush(

				RGB(GetRValue(startColor) + i * (255 - GetRValue(startColor)) / (n),
					GetGValue(startColor) + i * (255 - GetGValue(startColor)) / (n),
					GetBValue(startColor) + i * (255 - GetBValue(startColor)) / (n))));
			FillRect(hDC, &currentRect, NULL);
			SetRect(&currentRect, 
				currentRect.left + clientRect.right / (2 * n), 
				currentRect.top + clientRect.bottom / (2 * n),
				currentRect.right - clientRect.right / (2 * n),
				currentRect.bottom - clientRect.bottom / (2 * n));
			DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		}
		


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
