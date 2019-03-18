#undef UNICODE
#include <windows.h>
#include <string>
#include "KWnd.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window 1", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; 
	PAINTSTRUCT ps;
	HFONT hFont;
	static LOGFONT lf;
	RECT clientRect;
	const int startHeightFont = 20;
	const int startWidthFont = 8;
	const int changeHeightFont = 5;
	const int changeWidthFont = 2;

	static std::string text = "Test";

	switch (uMsg) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		lf.lfHeight = startHeightFont;
		lf.lfWidth = startWidthFont;
		hFont = CreateFontIndirect(&lf);
		ReleaseDC(hWnd, hDC); 
		break;
	
	case WM_CHAR:
		GetClientRect(hWnd, &clientRect);
		switch (wParam) {
		case '+':
			if (lf.lfHeight < clientRect.bottom
				&& 1.5 * lf.lfWidth * text.size() < clientRect.right) {
				text += (char) '+';
				lf.lfHeight += changeHeightFont;
				lf.lfWidth += changeWidthFont;
			} else {
				MessageBox(hWnd, "Font is too large", "Error", MB_OK);
			}
			break;
		case '-':
			if (lf.lfHeight > changeHeightFont && lf.lfWidth > changeWidthFont) {
				text += (char) '-';
				lf.lfHeight -= changeHeightFont;
				lf.lfWidth -= changeWidthFont;
			} else {
				MessageBox(hWnd, "Font is too small", "Error", MB_OK);
			}
			break;
		}
		InvalidateRect(hWnd, NULL, TRUE);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		hFont = CreateFontIndirect(&lf);
		GetClientRect(hWnd, &clientRect);
		SelectObject(hDC, hFont);
		if (text.size()) {
			DrawText(hDC, text.c_str(), -1, &clientRect, DT_CENTER | DT_VCENTER);
		}
		DeleteObject(SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT)));
		EndPaint(hWnd, &ps); 
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}
