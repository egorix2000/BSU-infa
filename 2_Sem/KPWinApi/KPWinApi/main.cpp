#include <windows.h>
#include <string>
#include <vector>
#include <cmath>
#include "KWnd.h"
#include "resource.h"
#include "Ball.h"
#include "draw.h"

#define TIMER_BALL 1
#define UPDATE_INTERVAL 50
#define SECOND 1000

enum side {RIGHT, LEFT};
enum direction {UP, DOWN};

const int DIAMETR = 40;
const int ROPE_LENGTH = 120;
const int SUSPENSION_Y = 10;
const int SUSPENSION_X = 200;
const double START_ANGLE = 3.1415926535 / 3;
const double PI = 3.1415926535;
const int N = 4;

double acceleration = 10;
std::vector<Ball> balls;
side currentSide;
direction currentDirection;
bool doesSystemActive;
double currentSpeed;


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
BOOL CALLBACK ChangeAccelerationDlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	
	KWnd mainWnd("Window Ball", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}


void createBalls() {

	int x = SUSPENSION_X + cos(1.5 * PI - START_ANGLE) * (ROPE_LENGTH + DIAMETR / 2);
	int y = 2 *  SUSPENSION_Y - sin(1.5 * PI - START_ANGLE) * (ROPE_LENGTH + DIAMETR / 2);
	balls.clear();
	balls.push_back(Ball(POINT{x, y}, DIAMETR / 2,
		RGB(rand() % 256, rand() % 256, rand() % 256)));

	double delta_angle = 2 * asin((DIAMETR / 2) / ((double)(ROPE_LENGTH + DIAMETR / 2)));
	double angle = 1.5 * PI - delta_angle * (N - 2) / 2.0;

	for (int i = 1; i < N; i++) {
		x = SUSPENSION_X + cos(angle) * (ROPE_LENGTH + DIAMETR / 2);
		y = 2 * SUSPENSION_Y - sin(angle) * (ROPE_LENGTH + DIAMETR / 2);
		balls.push_back(Ball(POINT{x, y}, DIAMETR / 2,
			RGB(rand() % 256, rand() % 256, rand() % 256)));
		angle += delta_angle;
	}

}

void onClick(HWND hWnd, LPARAM lParam) {
	for (std::vector<Ball>::iterator it = balls.begin(); it != balls.end(); it++) {
		if (((*it).center.x - LOWORD(lParam)) * ((*it).center.x - LOWORD(lParam)) +
			((*it).center.y - HIWORD(lParam)) * ((*it).center.y - HIWORD(lParam)) <= (DIAMETR * DIAMETR / 4)) {
			(*it).invertColor();
			break;
		}
	}
	InvalidateRect(hWnd, nullptr, true);
}

void moveBall() {
	if (currentDirection == UP) {
		currentSpeed -= acceleration * UPDATE_INTERVAL / SECOND;
	}
	else {
		currentSpeed += acceleration * UPDATE_INTERVAL / SECOND;
	}
	balls[0].center.x += currentSpeed;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC;
	PAINTSTRUCT ps;
	
	static HINSTANCE hInst;
	RECT clientRect;

	switch (uMsg) {
	case WM_CREATE:
		hInst = GetModuleHandle(NULL);
		createBalls();
		currentSide = LEFT;
		currentDirection = DOWN;
		doesSystemActive = true;
		currentSpeed = 0;
		SetTimer(hWnd, TIMER_BALL, UPDATE_INTERVAL, NULL);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		drawBallsWithRopes(hDC, balls, POINT{ SUSPENSION_X, 2 * SUSPENSION_Y });
		drawRect(hDC, RECT{ SUSPENSION_X, SUSPENSION_Y, SUSPENSION_X + ROPE_LENGTH, 2 * SUSPENSION_Y });
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_F3:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, ChangeAccelerationDlgProc);
			break;
		case 80:
			if (doesSystemActive) {
				KillTimer(hWnd, TIMER_BALL);
				doesSystemActive = false;
			}
			else {
				SetTimer(hWnd, TIMER_BALL, UPDATE_INTERVAL, NULL);
				doesSystemActive = true;
			}
			break;
		}
	case WM_LBUTTONUP:
		onClick(hWnd, lParam);
		break;
	case WM_TIMER:
		moveBall();
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

BOOL CALLBACK ChangeAccelerationDlgProc(HWND hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int newAcceleration;
	switch (uMsg) {
	case WM_INITDIALOG: 
		return TRUE;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDOK:
			newAcceleration = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, TRUE);
			if (newAcceleration >= 0) {
				acceleration = newAcceleration;
				EndDialog(hDlg, 0);
			}
			else {
				MessageBox(hDlg, "Acceleration must be more or equal to zero", "Error", MB_OK);
			}
			return TRUE;
		case IDCANCEL:
			EndDialog(hDlg, 0);
			return TRUE;
		}
		break;
	}
	return FALSE;
}

