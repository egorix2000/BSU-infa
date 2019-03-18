#undef UNICODE
#include <windows.h>
#include "KWnd.h"
#include "draw.h"

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

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;

	RECT clientRect;

	RECT ellipseRect;
	RECT rectangleRect;
	RECT sectorRect;
	RECT rhombusRect;

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		SetBkMode(hDC, TRANSPARENT);
		GetClientRect(hwnd, &clientRect);

		SetRect(&ellipseRect, clientRect.left, clientRect.top, clientRect.right / 2, clientRect.bottom / 2);
		SetRect(&rectangleRect, clientRect.right / 2, clientRect.top, clientRect.right, clientRect.bottom / 2);
		SetRect(&sectorRect, clientRect.left, clientRect.bottom / 2, clientRect.right / 2, clientRect.bottom);
		SetRect(&rhombusRect, clientRect.right / 2, clientRect.bottom / 2, clientRect.right, clientRect.bottom);
		
		MoveToEx(hDC, 0, clientRect.bottom / 2, nullptr);
		LineTo(hDC, clientRect.right, clientRect.bottom / 2);
		MoveToEx(hDC, clientRect.right / 2, 0, nullptr);
		LineTo(hDC, clientRect.right / 2, clientRect.bottom);

		DrawEllipse(hDC, ellipseRect, PS_DOT, 0, RGB(rand() % 255, rand() % 255, rand() % 255), RGB(rand() % 255, rand() % 255, rand() % 255));
		
		DrawRectangle(hDC, rectangleRect, PS_DASH, 0, RGB(rand() % 255, rand() % 255, rand() % 255), RGB(rand() % 255, rand() % 255, rand() % 255));
		
		DrawSector(hDC, sectorRect, PS_DASHDOTDOT, 0, RGB(rand() % 255, rand() % 255, rand() % 255), RGB(rand() % 255, rand() % 255, rand() % 255));
		
		DrawRhombus(hDC, rhombusRect, PS_SOLID, 3, RGB(rand() % 255, rand() % 255, rand() % 255), RGB(rand() % 255, rand() % 255, rand() % 255));

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
