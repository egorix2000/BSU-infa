#undef UNICODE
#include <windows.h>
#include <sstream>
#include "KWnd.h"
#include "style.h"

// start C:\BSU\2_Sem\TP05\Debug\Grid_4 '4 5'

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int M;
int N;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 1", hInstance, nCmdShow, WndProc);

	std::stringstream ss(lpCmdLine);
	ss >> M;
	ss >> N;

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

	switch (message) {
	case WM_PAINT:
		hDC = BeginPaint(hwnd, &ps);
		GetClientRect(hwnd, &clientRect);

		for (int i = 1; i < M; i++) {
			MoveToEx(hDC, 0, i * clientRect.bottom / M, nullptr);
			LineTo(hDC, clientRect.right, i * clientRect.bottom / M);
		}

		for (int i = 1; i < N; i++) {
			MoveToEx(hDC, i * clientRect.right / N, 0, nullptr);
			LineTo(hDC, i * clientRect.right / N, clientRect.bottom);
		}

		for (int i = 1; i < M; i++) {
			for (int j = 1; j < N; j++) {
				SelectObject(hDC, CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255)));
				Ellipse(hDC, 
					j * clientRect.right / N - MARGIN_TEN_PX, i * clientRect.bottom / M - MARGIN_TEN_PX,
					j * clientRect.right / N + MARGIN_TEN_PX, i * clientRect.bottom / M + MARGIN_TEN_PX);
				DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
			}
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
