#pragma once
struct Point
{
	int x;
	int y;
	friend bool operator ==(const Point pointLeft, const Point pointRight) {
		return (pointLeft.x == pointRight.x && pointLeft.y == pointRight.y) ? true : false;
	}

	Point& operator =(const Point& point) {
		x = point.x;
		y = point.y;
		return *this;
	}
};