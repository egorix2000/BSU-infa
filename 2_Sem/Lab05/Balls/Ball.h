#pragma once
#include <windows.h>
#include "Point.h"

class Ball
{
private:
	Point center_;
	int radius_;
	COLORREF color_;
public:
	Ball();
	Ball(Point &center, int radius);
	Ball(const Ball& ball);
	Point getCenter() const;
	int getRadius() const;
	Ball& increaseRadius(int n);
	COLORREF getColor() const;
	friend bool operator ==(const Ball& ballLeft, const Ball& ballRight);
	Ball& operator =(const Ball& ball);
};

