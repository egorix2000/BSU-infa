#undef UNICODE
#include <windows.h>
#include <string>
#include <algorithm> 
#include <ctime>
#include <vector>
#include "KWnd.h"
#include "Ball.h"
#include "Point.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	MSG msg;
	srand(time(NULL));
	
	KWnd mainWnd("Window 3", hInstance, nCmdShow, WndProc);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	HDC hDC; 
	PAINTSTRUCT ps;
	RECT clientRect;
	static std::vector<Ball> balls;
	bool isInsideBall;
	Point mouseClick;
	Ball clickedBall;
	int startRadius = 5;
	int increaseRate = 3;

	switch (uMsg) {
	case WM_LBUTTONDOWN:
		isInsideBall = false;
		mouseClick.x = LOWORD(lParam);
		mouseClick.y = HIWORD(lParam);
		for (std::vector<Ball>::iterator i = balls.begin(); i != balls.end(); i++) {
			if (((*i).getCenter().x - mouseClick.x) * ((*i).getCenter().x - mouseClick.x) +
				((*i).getCenter().y - mouseClick.y) * ((*i).getCenter().y - mouseClick.y) <
				(*i).getRadius() * (*i).getRadius()) {
				isInsideBall = true;
				clickedBall = (*i);
				balls.erase(i);
				clickedBall.increaseRadius(increaseRate);
				balls.insert(balls.begin(), clickedBall);
				break;
			}
		}
		if (!isInsideBall) {
			balls.insert(balls.begin(), Ball(mouseClick, startRadius));
		}
		InvalidateRect(hWnd, nullptr, NULL);
		break;
	case WM_PAINT:
		hDC = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &clientRect);
		for (std::vector<Ball>::reverse_iterator i = balls.rbegin(); i != balls.rend(); i++) {
			SelectObject(hDC, CreateSolidBrush((*i).getColor()));
			Ellipse(hDC, (*i).getCenter().x - (*i).getRadius(),
				(*i).getCenter().y - (*i).getRadius(),
				(*i).getCenter().x + (*i).getRadius(),
				(*i).getCenter().y + (*i).getRadius());
		}
		DeleteObject(SelectObject(hDC, GetStockObject(BLACK_BRUSH)));
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
