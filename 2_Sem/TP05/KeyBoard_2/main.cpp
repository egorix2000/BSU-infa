#undef UNICODE
#include <windows.h>
#include <string>
#include "KWnd.h"

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
	PAINTSTRUCT ps;
	TEXTMETRIC tm;

	static std::string text;
	std::string symb;

	static int charWidth, charHeight;
	static int clientWidth, clientHeight;
	static int nCharPerLine;
	static int nClientLines;
	static int xCaret = 0, yCaret = 0;

	int x, y, i;
	int curIndex;
	int nLines;
	int nTailChar;

	switch (uMsg) {
	case WM_CREATE:
		hDC = GetDC(hWnd);
		SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT)); 
		GetTextMetrics(hDC, &tm);
		charWidth = tm.tmAveCharWidth;
		charHeight = tm.tmHeight;
		ReleaseDC(hWnd, hDC); 
		break;
	case WM_SIZE:
		clientWidth = LOWORD(lParam);
		clientHeight = HIWORD(lParam);
		nCharPerLine = max(1, clientWidth / charWidth);
		nClientLines = max(1, clientHeight / charHeight);
		if (hWnd == GetFocus())
			SetCaretPos(xCaret * charWidth, yCaret * charHeight);
		break;
	case WM_SETFOCUS:
		CreateCaret(hWnd, NULL, 0, charHeight); 
		SetCaretPos(xCaret * charWidth, yCaret * charHeight); 
		ShowCaret(hWnd);
		break;
	case WM_KILLFOCUS:
		HideCaret(hWnd);
		DestroyCaret();
		break;
	
	case WM_CHAR:
		switch (wParam) {
		case '\b':
			if (xCaret <= 0) {
				if (yCaret > 0) {
					xCaret = nCharPerLine - 1;
					yCaret--;
				}
			} else {
				xCaret--;
			}
			curIndex = yCaret * nCharPerLine + xCaret;
			if (curIndex < text.size()) {
				text.erase(curIndex, 1);
				InvalidateRect(hWnd, NULL, TRUE);
			}
			break;
		default:
			curIndex = yCaret * nCharPerLine + xCaret; 
			text += (char)wParam;

			InvalidateRect(hWnd, NULL, TRUE);
			if (++xCaret == nCharPerLine) {
				xCaret = 0;
				if (++yCaret == nClientLines) {
					MessageBox(hWnd, "No space for text", "Error", MB_OK);
					yCaret--;
				}
			}
			break;
		}
		SetCaretPos(xCaret * charWidth, yCaret * charHeight); 
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		SelectObject(hDC, GetStockObject(SYSTEM_FIXED_FONT));
		if (text.size()) {
			nLines = text.size() / nCharPerLine; 
			nTailChar = text.size() % nCharPerLine; 
			for (y = 0; y < nLines; ++y) {
				TextOut(hDC, 0, y*charHeight, text.c_str() + y * nCharPerLine, nCharPerLine);
			}
			TextOut(hDC, 0, y*charHeight, text.c_str() + y * nCharPerLine, nTailChar);
		}
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
