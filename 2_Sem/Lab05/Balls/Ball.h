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
	Ball(Point &center, int radius);
	Ball(const Ball& ball);
	Point getCenter() const;
	int getRadius() const;
	Ball& increaseRadius(int n);
	COLORREF getColor() const;
};

