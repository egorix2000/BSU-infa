#undef UNICODE
#include <windows.h>
#include <cmath>
#include "KWnd.h"

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
	POINT rhombusPoints[4];

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

		SelectObject(hDC, CreatePen(PS_DOT, 0, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		Ellipse(hDC, ellipseRect.left + 10, ellipseRect.top + 10, ellipseRect.right - 10, ellipseRect.bottom - 50);
		DrawText(hDC, "Ellipse", -1, &ellipseRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		
		SelectObject(hDC, CreatePen(PS_DASH, 0, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		Rectangle(hDC, rectangleRect.left + 10, rectangleRect.top + 10, rectangleRect.right - 10, rectangleRect.bottom - 50);
		DrawText(hDC, "Rectangle", -1, &rectangleRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		
		SelectObject(hDC, CreatePen(PS_DASHDOTDOT, 0, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		Pie(hDC, sectorRect.left + 10, sectorRect.top + 10, sectorRect.right - 10, sectorRect.bottom - 50,
			sectorRect.right - 10, 
			sectorRect.top + (sectorRect.bottom - sectorRect.top - 40) / 2,
			sectorRect.left + (sectorRect.right - sectorRect.left) / 2 + (sectorRect.right - sectorRect.left - 20)*sqrt(3)/4,
			sectorRect.top + (sectorRect.bottom - sectorRect.top - 40) / 2 - (sectorRect.right - sectorRect.left - 20) / 4);
		DrawText(hDC, "Sector", -1, &sectorRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		
		SelectObject(hDC, CreatePen(PS_SOLID, 3, RGB(rand() % 255, rand() % 255, rand() % 255)));
		SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
		rhombusPoints[0] = { rhombusRect.left + 10, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - 40) / 2 };
		rhombusPoints[1] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.top + 10 };
		rhombusPoints[2] = { rhombusRect.right - 10, rhombusRect.top + (rhombusRect.bottom - rhombusRect.top - 40) / 2 };
		rhombusPoints[3] = { rhombusRect.left + (rhombusRect.right - rhombusRect.left) / 2, rhombusRect.bottom - 50 };
		Polygon(hDC, rhombusPoints, 4);
		DrawText(hDC, "Rhombus", -1, &rhombusRect, DT_SINGLELINE | DT_CENTER | DT_BOTTOM);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));

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
