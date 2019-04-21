#include <windows.h>
#include <string>
#include <cmath>
#include "KWnd.h"
#include "resource.h"

#define TIMER_BALL 1
#define UPDATE_INTERVAL 50

const int DIAMETR = 40;
const int MARGIN = 10;
const int ACCELERATION = 60;

enum direction { UP, DOWN };

int height;
int ballY;
double speed;
direction ballDirection;

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ChangeHeightDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

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
	HDC memoryHDC;
	HBITMAP hbmMem;
	HANDLE hOld;
	PAINTSTRUCT ps;
	
	RECT clientRect;

	static HINSTANCE hInst;

	switch (uMsg) {
	case WM_CREATE:
		hInst = GetModuleHandle(NULL);
		height = 240;
		ballY = height;
		ballDirection = DOWN;
		speed = 0;
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

		MoveToEx(hDC, clientRect.left + 4 * MARGIN, clientRect.bottom - 3 * MARGIN, nullptr);
		LineTo(hDC, clientRect.left + 4 * MARGIN, clientRect.bottom - 3 * MARGIN - ballY - 1);

		EndPaint(hWnd, &ps);
		break;
	case WM_RBUTTONDOWN:
		DialogBox(hInst, MAKEINTRESOURCE(IDD_CHANGE_HEIGHT), hWnd, ChangeHeightDlgProc);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_F5:
			ballY = height;
			ballDirection = DOWN;
			speed = 0;
			break;
		}
	case WM_TIMER:
		if (ballDirection == UP) {
			speed -= ACCELERATION * UPDATE_INTERVAL / 1000;
			ballY += speed;
		} 
		else {
			speed += ACCELERATION * UPDATE_INTERVAL / 1000;
			ballY -= speed;
		}
		if (ballY <= 0) {
			ballY = 0;
			ballDirection = UP;
			speed = sqrt(2 * ACCELERATION * height * UPDATE_INTERVAL / 1000);
		}
		if (ballY >= height) {
			ballY = height;
			ballDirection = DOWN;
			speed = 0;
		}
		InvalidateRect(hWnd, nullptr, true);
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

BOOL CALLBACK ChangeHeightDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HWND hWndEdit;
	switch (uMsg) {
	case WM_INITDIALOG: 
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			hWndEdit = GetDlgItem(hDlg, IDC_EDIT1);
			height = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, FALSE);
			ballY = height;
			ballDirection = DOWN;
			speed = 0;
			EndDialog(hDlg, 0);
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

