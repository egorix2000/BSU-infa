#include <windows.h>
#include <cmath>
#include "KWnd.h"
#include "draw.h"

#define ID_EDITCHILD 100

bool doesSelectionActive;
RECT selection;
const int MIN_SELECT = 10;

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

	RECT clientRect;

	switch (message) {
	case WM_CREATE:
		doesSelectionActive = false;
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		if (doesSelectionActive) {
			drawRect(hDC, selection);
		}
		POINT origin = getOriginAtWindow(clientRect);
		drawAxes(hDC, clientRect, origin);
		drawScalesOfAxes(hDC, clientRect, origin);
		drawPointerToAxes(hDC, clientRect, origin);
		drawGraphic(hDC, clientRect);
		drawPointAtGraph(hDC, clientRect, origin);
		EndPaint(hWnd, &ps);
		break;
	case WM_MOUSEMOVE:
		onMouseMove(hWnd, lParam);
		break;
	case WM_LBUTTONDOWN:
		onLButtonDown(hWnd, lParam);
		break;
	case WM_LBUTTONUP:
		onLButtonUp(hWnd, lParam);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void onLButtonDown(HWND& hwnd, LPARAM lParam) {
	doesSelectionActive = true;
	selection.left = LOWORD(lParam);
	selection.top = HIWORD(lParam);
}

void onLButtonUp(HWND& hwnd, LPARAM lParam) {
	if (doesSelectionActive) {
		RECT rect;
		GetClientRect(hwnd, &rect);
		selection.right = LOWORD(lParam);
		selection.bottom = HIWORD(lParam);
		if (abs(selection.right - selection.left) >= MIN_SELECT
			&& abs(selection.bottom - selection.top) >= MIN_SELECT) {
			resizeAxes(rect);
		}
		doesSelectionActive = false;
		InvalidateRect(hwnd, NULL, TRUE);
	}
}

void onMouseMove(HWND& hwnd, LPARAM lParam) {
	selection.right = LOWORD(lParam);
	selection.bottom = HIWORD(lParam);
	InvalidateRect(hwnd, NULL, TRUE);
}