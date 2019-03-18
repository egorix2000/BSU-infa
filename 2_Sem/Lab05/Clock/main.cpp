#undef UNICODE
#include <windows.h>
#include <string>
#include "KWnd.h"
#include "Clock.h"
#include "style.h"

#define TIMER_SEC 1

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 2", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; 
	HFONT hFont;
	static LOGFONT lf;
	PAINTSTRUCT ps;
	RECT clientRect;
	int radius;
	static Clock clock;
	TCHAR outputSeconds[20];

	switch (uMsg) {
	case WM_CREATE:
		SetTimer(hWnd, TIMER_SEC, 1000, NULL);
		break;
	case WM_KEYDOWN:
		if (wParam == 83) {
			clock.setSeconds(0);
		}
		break;
	case WM_CHAR:
		GetClientRect(hWnd, &clientRect);
		switch (wParam) {
		case '+':
			clock.setIsActive(true);
			break;
		case '-':
			clock.setIsActive(false);
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);

		GetClientRect(hWnd, &clientRect);
		radius = min(clientRect.bottom, clientRect.right) / 2 - MARGIN_TEN_PX;
		lf.lfHeight = radius;
		hFont = CreateFontIndirect(&lf);
		SelectObject(hDC, hFont);
		Ellipse(hDC, clientRect.right / 2 - radius, clientRect.bottom / 2 - radius, 
			clientRect.right / 2 + radius, clientRect.bottom / 2 + radius);
		sprintf_s(outputSeconds, "%d", clock.getSeconds());
		DrawText(hDC, outputSeconds, -1, &clientRect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

		DeleteObject(SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT)));
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		if (clock.getIsActive()) {
			clock++;
			InvalidateRect(hWnd, nullptr, NULL);
		}
		break;
	case WM_DESTROY:
		KillTimer(hWnd, TIMER_SEC);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
