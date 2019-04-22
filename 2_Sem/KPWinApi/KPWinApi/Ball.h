#pragma once
#include <windows.h>

class Ball {
public:
	POINT center;
	int radius;
	COLORREF color;

	Ball(POINT sourceCenter, int sourceRadius, COLORREF sourceColor);
	Ball& invertColor();
};