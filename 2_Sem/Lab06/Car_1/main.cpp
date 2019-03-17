#undef UNICODE
#include <windows.h>
#include <sstream>
#include "KWnd.h"
#include "draw.h"
#include "Car.h"

#define TIMER_CAR 1

//start C:\BSU\2_Sem\Lab06\Debug\Car_1 '1 30'

int mode;
int speed;
const int UPDATE_INTERVAL = 100;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	std::stringstream ss(lpCmdLine);
	ss >> mode >> speed;
	mode = 1;
	speed = 30;
	
	KWnd mainWnd("Window 1", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Car car;
	HDC hDC;
	PAINTSTRUCT ps;
	RECT clientRect;

	switch (message) {
	case WM_CREATE:
		GetClientRect(hWnd, &clientRect);
		SetTimer(hWnd, TIMER_CAR, UPDATE_INTERVAL, NULL);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);

		//DrawBitmap(hDC, car.getX(), car.getY(), car.getX() + car.getWidth(), car.getY() + car.getHeight(), hBmpCar, SRCCOPY);
		
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		GetClientRect(hWnd, &clientRect);
		switch (car.getDirection()) {
		case 1:
			car += speed * UPDATE_INTERVAL / 1000;
			break;
		case 2:
			car -= speed * 1000 / UPDATE_INTERVAL;
			break;
		}

		if (car.getX() > clientRect.right || car.getX() < -car.getWidth()) {
			switch (mode) {
			case 1:
				car.setX(-car.getWidth());
				break;
			case 2:
				car.changeDirection();
				break;
			}
		}
		InvalidateRect(hWnd, nullptr, NULL);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, TIMER_CAR);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
