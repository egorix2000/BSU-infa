#include "Ball.h"

Ball::Ball(POINT sourceCenter, int sourceRadius, COLORREF sourceColor) {
	center.x = sourceCenter.x;
	center.y = sourceCenter.y;
	radius = sourceRadius;
	color = sourceColor;
}

Ball& Ball::invertColor() {
	color = RGB(255 - GetRValue(color), 255 - GetGValue(color), 255 - GetBValue(color));
	return *this;
}