#include <windows.h>
#include <string>
#include <vector>
#include <cmath>
#include "KWnd.h"
#include "resource.h"
#include "Ball.h"
#include "draw.h"
#include "coordinates.h"

#define TIMER_BALL 1
#define UPDATE_INTERVAL 50
#define SECOND 1000
#define METR 1000

enum direction {UP, DOWN};

const int RADIUS = 20;
const int ROPE_LENGTH = 120;
const int MARGIN_TOP_RECT = 20;
const int MARGIN_LEFT_RECT = 280;
const int SUSPENSION_Y = 40;
const int SUSPENSION_X = 200;
const double START_ANGLE = 3.1415926535 * 11 / 10;
const double PI = 3.1415926535;
const int N = 4;

double acceleration;
std::vector<Ball> balls;
direction currentDirection;
bool doesSystemActive;
int currentBallIndex;
int neighbourIndex;


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
	balls.clear();
	balls.push_back(Ball(START_ANGLE, ROPE_LENGTH + RADIUS, RADIUS,
		RGB(rand() % 256, rand() % 256, rand() % 256)));

	double delta_angle = 2 * asin((RADIUS) / ((double)(ROPE_LENGTH + RADIUS)));
	double angle = 1.5 * PI - delta_angle * (N - 2) / 2.0;

	for (int i = 1; i < N; i++) {
		balls.push_back(Ball(angle, ROPE_LENGTH + RADIUS, RADIUS,
			RGB(rand() % 256, rand() % 256, rand() % 256)));
		angle += delta_angle;
	}

}

void onClick(HWND hWnd, LPARAM lParam) {
	POINT center;
	int x = LOWORD(lParam);
	int y = HIWORD(lParam);
	for (std::vector<Ball>::iterator it = balls.begin(); it != balls.end(); it++) {
		center = polarToDecart((*it).angle, (*it).radius);
		if ((center.x - LOWORD(lParam) + SUSPENSION_X) * (center.x - LOWORD(lParam) + SUSPENSION_X) +
			(- center.y - HIWORD(lParam) + SUSPENSION_Y) * (- center.y - HIWORD(lParam) + SUSPENSION_Y) <= (RADIUS * RADIUS)) {
			(*it).invertColor();
			break;
		}
	}
	InvalidateRect(hWnd, nullptr, true);
}

void moveBall() {
	POINT centerNeighbour;
	POINT center = polarToDecart(balls[currentBallIndex].angle, balls[currentBallIndex].radius);
	centerNeighbour = polarToDecart(balls[neighbourIndex].angle, balls[neighbourIndex].radius);

	if (balls[0].angle <= START_ANGLE) {
		currentDirection = DOWN;
		balls[0].angle = START_ANGLE;
	}
	if (balls[N - 1].angle >= 3 * PI - START_ANGLE) {
		currentDirection = DOWN;
		balls[N - 1].angle = 3 * PI - START_ANGLE;
	}
	if (calcSquaredDistance(center, centerNeighbour) <= 4 * RADIUS * RADIUS) {
		currentDirection = UP;
		if (currentBallIndex == 0) {
			currentBallIndex = N - 1;
			neighbourIndex = N - 2;
		}
		else {
			currentBallIndex = 0;
			neighbourIndex = 1;
		}
	}

	if ((currentDirection == DOWN && currentBallIndex == 0) ||
		(currentDirection == UP && currentBallIndex == N - 1)) {
		balls[currentBallIndex].angle += acceleration * UPDATE_INTERVAL / (10*SECOND);
	}
	else {
		balls[currentBallIndex].angle -= acceleration * UPDATE_INTERVAL / (10*SECOND);
	}
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
		currentDirection = DOWN;
		doesSystemActive = true;
		currentBallIndex = 0; 
		neighbourIndex = 1;
		acceleration = 10;
		SetTimer(hWnd, TIMER_BALL, UPDATE_INTERVAL, NULL);
		break;

	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		drawBallsWithRopes(hDC, balls, POINT{ SUSPENSION_X, SUSPENSION_Y });
		drawRect(hDC, RECT{ SUSPENSION_X, MARGIN_TOP_RECT, MARGIN_LEFT_RECT, SUSPENSION_Y }, RGB(0, 100, 200));
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

