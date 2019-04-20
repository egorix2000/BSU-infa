#include <windows.h>
#include <string>
#include "KWnd.h"

#define TIMER_BALL 1
#define UPDATE_INTERVAL 50

const int DIAMETR = 40;
const int MARGIN = 10;
const int ACCELERATION = 60;

enum direction { UP, DOWN };

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window Ball", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; 
	PAINTSTRUCT ps;
	
	RECT clientRect;

	static int height;
	static int ballY;
	static direction ballDirection;

	switch (uMsg) {
	case WM_CREATE:
		height = 240;
		ballY = 0;
		ballDirection = UP;
		SetTimer(hWnd, TIMER_BALL, UPDATE_INTERVAL, NULL);
		break;
	
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);

		SelectObject(hDC, CreateSolidBrush(RGB(0, 145, 255)));
		Rectangle(hDC, clientRect.left + MARGIN, clientRect.bottom - 3 * MARGIN, 
			clientRect.left + 7 * MARGIN, clientRect.bottom - MARGIN);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));

		SelectObject(hDC, CreateSolidBrush(RGB(200, 90, 140)));
		Ellipse(hDC, clientRect.left + 2 * MARGIN, clientRect.bottom - 3 * MARGIN - ballY - DIAMETR,
			clientRect.left + 2 * MARGIN + DIAMETR, clientRect.bottom - 3 * MARGIN - ballY);
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		if (ballDirection == UP)
			ballY++;
		else
			ballY--;
		if (ballY <= 0) {
			ballY = 0;
			ballDirection = UP;
		}
		if (ballY >= height) {
			ballY = height;
			ballDirection = DOWN;
		}
		InvalidateRect(hWnd, nullptr, NULL);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, TIMER_BALL);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
