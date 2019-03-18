#undef UNICODE
#include <windows.h>
#include "KWnd.h"
#include "resource.h"
#include "Clock.h"
#include "draw.h"

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
	int lessSide;
	HDC hDC;
	PAINTSTRUCT ps;
	RECT clientRect;
	int leftTopMargin;
	int clockSide;

	switch (message) {
	case WM_CREATE:
		hBmpClock = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CLOCK));
		GetObject(hBmpClock, sizeof(bm), (LPSTR)&bm);
		SetTimer(hWnd, TIMER_SEC, 1000, NULL);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		lessSide = min(clientRect.bottom, clientRect.right);

		leftTopMargin = lessSide * 0.05;
		clockSide = lessSide * 0.9;

		DrawClock(hDC, leftTopMargin, leftTopMargin, clockSide, clockSide,
			hBmpClock, SRCCOPY, clock.getSeconds(), clock.getMinutes());

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
