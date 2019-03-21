#undef UNICODE
#include <windows.h>
#include <sstream>
#include "KWnd.h"
#include "draw.h"
#include "Car.h"
#include "resource.h"

#define TIMER_CAR 1
#define UPDATE_INTERVAL 50

#define FORWARD_MODE 1
#define BACKWARD_MODE 2

//start C:\BSU\2_Sem\Lab06\Debug\Car_1 '1 70'

int mode;
int speed;
const double CAR_SIZE_TO_WINDOW_SIZE = 0.2;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	std::stringstream ss(lpCmdLine);
	ss >> mode >> speed;
	//mode = FORWARD_MODE;
	//speed = 70;
	
	KWnd mainWnd("Window 1", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static Car* car;
	HDC hDC;
	PAINTSTRUCT ps;
	RECT clientRect;
	static HBITMAP hBmpCarForward;
	static HBITMAP hBmpCarBackward;
	static SIZE carForwardImageSize;
	static SIZE carBackwardImageSize;
	BITMAP bm;
	int carWidth;
	int carHeight;

	switch (message) {
	case WM_CREATE:
		hBmpCarForward = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CAR_FORWARD));
		hBmpCarBackward = LoadBitmap(GetModuleHandle(NULL), MAKEINTRESOURCE(IDB_CAR_BACKWARD));
		GetBitmapDimensionEx(hBmpCarForward, &carForwardImageSize);
		GetBitmapDimensionEx(hBmpCarBackward, &carBackwardImageSize);

		GetObject(hBmpCarForward, sizeof(bm), &bm);
		GetClientRect(hWnd, &clientRect);
		carWidth = bm.bmWidth * clientRect.bottom * CAR_SIZE_TO_WINDOW_SIZE / bm.bmHeight;
		carHeight = clientRect.bottom * CAR_SIZE_TO_WINDOW_SIZE;
		car = new Car(-carWidth, clientRect.bottom/2, speed, FORWARD, carWidth, carHeight);
		SetTimer(hWnd, TIMER_CAR, UPDATE_INTERVAL, NULL);
		break;
	case WM_SIZE:
		GetObject(hBmpCarForward, sizeof(bm), &bm);
		carWidth = bm.bmWidth * HIWORD(lParam) * CAR_SIZE_TO_WINDOW_SIZE / bm.bmHeight;
		carHeight = HIWORD(lParam) * CAR_SIZE_TO_WINDOW_SIZE;

		car->setWidth(carWidth);
		car->setHeight(carHeight);
		car->setY(HIWORD(lParam) / 2);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);

		switch (car->getDirection()) {
		case FORWARD:
			DrawBitmap(hDC, car->getX(), car->getY(), car->getWidth(),
				car->getHeight(), hBmpCarForward, SRCCOPY);
			break;
		case BACKWARD:
			DrawBitmap(hDC, car->getX(), car->getY(), car->getWidth(),
				car->getHeight(), hBmpCarBackward, SRCCOPY);
			break;
		}
		
		EndPaint(hWnd, &ps);
		break;
	case WM_TIMER:
		GetClientRect(hWnd, &clientRect);
		switch (car->getDirection()) {
		case FORWARD:
			car->move(car->getSpeed() * UPDATE_INTERVAL / 1000);
			break;
		case BACKWARD:
			car->move((-1) * car->getSpeed() * UPDATE_INTERVAL / 1000);
			break;
		}

		if (car->getX() > clientRect.right || car->getX() < -car->getWidth()) {
			switch (mode) {
			case FORWARD_MODE:
				car->setX(-car->getWidth());
				break;
			case BACKWARD_MODE:
				car->changeDirection();
				break;
			}
		}
		InvalidateRect(hWnd, nullptr, NULL);
		UpdateWindow(hWnd);
		break;
	case WM_DESTROY:
		delete car;
		KillTimer(hWnd, TIMER_CAR);
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
