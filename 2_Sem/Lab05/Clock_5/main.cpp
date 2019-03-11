#undef UNICODE
#include <windows.h>
#include <cmath>
#include "KWnd.h"
#include "resource.h"
#include "Clock.h"

#define TIMER_SEC 1

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 1", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HBITMAP hBmpClock;
	static Clock clock(0, 0);
	static BITMAP bm;
	HDC hDC;
	HDC hMemoryDC;
	PAINTSTRUCT ps;

	switch (message) {
	case WM_CREATE:
		hBmpClock = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CLOCK));
		GetObject(hBmpClock, sizeof(bm), (LPSTR)&bm);
		SetTimer(hWnd, TIMER_SEC, 1000, NULL);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		hMemoryDC = CreateCompatibleDC(hDC);
		SelectObject(hMemoryDC, hBmpClock);
		BitBlt(hDC, 25, 25, bm.bmWidth, bm.bmHeight, hMemoryDC, 0, 0, SRCCOPY);
		DeleteDC(hMemoryDC);

		SelectObject(hDC, CreatePen(PS_SOLID, 2, RGB(0, 0, 0)));
		MoveToEx(hDC, 25 + bm.bmWidth / 2, 25 + bm.bmHeight / 2, nullptr);
		LineTo(hDC, (bm.bmWidth / 2)*sin(clock.getSeconds() * (acos(-1) / 30)) + 25 + bm.bmWidth / 2,
			-(bm.bmHeight / 2)*cos(clock.getSeconds() * (acos(-1) / 30)) + 25 + bm.bmHeight / 2);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));

		SelectObject(hDC, CreatePen(PS_SOLID, 4, RGB(0, 0, 0)));
		MoveToEx(hDC, 25 + bm.bmWidth / 2, 25 + bm.bmHeight / 2, nullptr);
		LineTo(hDC, (bm.bmWidth / 4)*sin( clock.getMinutes() * (acos(-1) / 30)) + 25 + bm.bmWidth / 2,
			-(bm.bmHeight / 4)*cos(clock.getMinutes() * (acos(-1) / 30)) + 25 + bm.bmHeight / 2);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_PEN)));

		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		clock++;
		InvalidateRect(hWnd, nullptr, NULL);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, TIMER_SEC);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
