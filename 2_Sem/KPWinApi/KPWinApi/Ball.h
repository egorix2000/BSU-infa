#pragma once
#include <windows.h>

class Ball {
public:
	//polar coordinates
	double angle;
	double radius;

	int ballRadius;
	COLORREF color;

	Ball(double sourceAngle, double sourceRadius, int sourceBallRadius, COLORREF sourceColor);
	Ball& invertColor();
};