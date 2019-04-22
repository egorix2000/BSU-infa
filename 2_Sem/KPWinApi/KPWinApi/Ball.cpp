#include "Ball.h"

Ball::Ball(double sourceAngle, double sourceRadius, int sourceBallRadius, COLORREF sourceColor) {
	angle = sourceAngle;
	radius = sourceRadius;
	ballRadius = sourceBallRadius;
	color = sourceColor;
}

Ball& Ball::invertColor() {
	color = RGB(255 - GetRValue(color), 255 - GetGValue(color), 255 - GetBValue(color));
	return *this;
}