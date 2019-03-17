#undef UNICODE
#include <windows.h>
#include <sstream>
#include <algorithm>
#include <vector>
#include "KWnd.h"
#include "draw.h"
#include "TrafficLight.h"
#include "RedLight.h"
#include "GreenLight.h"
#include "YellowLight.h"
#include "Light.h"
#include "Circle.h"

//start C:\BSU\2_Sem\Lab06\Debug\TrafficLight_2 '10 5 10 3'

#define TIMER_FLICKER_INTERVAL 1
#define TIMER_LIGHT 2
#define TIMER_FLICKER 3
#define TIMER_FLICKER_SIZE_INTERVAL 4

std::vector<int> timeColors;
int timeFlicker;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;

	int timeColor;
	std::stringstream ss(lpCmdLine);
	for (int i = 0; i < 3; i++) {
		ss >> timeColor;
		//timeColor = 10;
		timeColor *= 1000;
		timeColors.push_back(timeColor);
	}
	//timeColors[1] = 5000;
	ss >> timeFlicker;
	//timeFlicker = 3;
	timeFlicker *= 1000;

	KWnd mainWnd("Window 1", hInstance, nCmdShow, WndProc);

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
	static TrafficLight *trafficLight;
	static Circle circles[3];
	RECT trafficLightRect;
	std::vector<Light*> lights;
	int trafficLightHeight;
	int x, y;

	switch (message) {
	case WM_CREATE:
		GetClientRect(hWnd, &clientRect);
		lights.push_back(&RedLight(timeColors[0]));
		lights.push_back(&YellowLight(timeColors[1]));
		lights.push_back(&GreenLight(timeColors[2]));
		trafficLight = new TrafficLight(lights, timeFlicker);
		SetTimer(hWnd, TIMER_LIGHT, trafficLight->getCurrentLight().getTime(), NULL);
		SetTimer(hWnd, TIMER_FLICKER, 
			trafficLight->getCurrentLight().getTime() - trafficLight->getTimeFlicker(), NULL);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);

		trafficLightHeight = min(clientRect.bottom - 20, (clientRect.right - 20)*3);

		SetRect(&trafficLightRect, 10, 10, 10 + trafficLightHeight / 3, 10 + trafficLightHeight);

		DrawTrafficLight(hDC, trafficLightRect, *trafficLight, circles);

		EndPaint(hWnd, &ps);
		break;
	case WM_LBUTTONUP:
		x = LOWORD(lParam);
		y = HIWORD(lParam);
		for (int i = 0; i < 3; i++) {
			if (LOWORD(lParam) > circles[i].xLeft && LOWORD(lParam) < circles[i].xRight &&
				HIWORD(lParam) > circles[i].yTop && HIWORD(lParam) < circles[i].yBottom) {
				(*std::find_if(trafficLight->getLights().begin(), trafficLight->getLights().end(), 
					[i](const Light* light) {
					return light->getType() == circles[i].type;
				}))->switchIsFlickerSize();
				break;
			}
		}

		KillTimer(hWnd, TIMER_FLICKER_SIZE_INTERVAL);
		if (std::count_if(trafficLight->getLights().begin(), trafficLight->getLights().end(),
			[](const Light* light) {
			return light->getIsFlickerSize() == true;
		}) != 0) {
			SetTimer(hWnd, TIMER_FLICKER_SIZE_INTERVAL, 300, NULL);
		}
		break;
	case WM_TIMER:
		switch (wParam) {
		case TIMER_FLICKER_INTERVAL:
			trafficLight->switchIsMainColor();
			break;
		case TIMER_LIGHT:
			KillTimer(hWnd, TIMER_FLICKER_INTERVAL);
			KillTimer(hWnd, TIMER_LIGHT);
			KillTimer(hWnd, TIMER_FLICKER);
			trafficLight->switchColor();
			trafficLight->setIsMainColor(true);
			SetTimer(hWnd, TIMER_FLICKER, 
				trafficLight->getCurrentLight().getTime() - trafficLight->getTimeFlicker(), NULL);
			SetTimer(hWnd, TIMER_LIGHT, trafficLight->getCurrentLight().getTime(), NULL);
			break;
		case TIMER_FLICKER:
			KillTimer(hWnd, TIMER_FLICKER);
			SetTimer(hWnd, TIMER_FLICKER_INTERVAL, 500, NULL);
			break;
		case TIMER_FLICKER_SIZE_INTERVAL:
			for (int i = 0; i < 3; i++) {
				if ((*trafficLight)[i].getIsFlickerSize()) {
					circles[i].isBig = !circles[i].isBig;
				}
			}
			break;
		}
		InvalidateRect(hWnd, nullptr, NULL);
		break;
	case WM_DESTROY:
		KillTimer(hWnd, TIMER_FLICKER_INTERVAL);
		KillTimer(hWnd, TIMER_LIGHT);
		KillTimer(hWnd, TIMER_FLICKER);
		KillTimer(hWnd, TIMER_FLICKER_SIZE_INTERVAL);
		delete trafficLight;
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
