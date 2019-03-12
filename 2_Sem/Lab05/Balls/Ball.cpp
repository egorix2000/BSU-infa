#include "Ball.h"
#include "Point.h"
#include <windows.h>

Ball::Ball(Point &center, int radius)
{
	center_.x = center.x;
	center_.y = center.y;
	radius_ = radius;
	color_ = RGB(rand() % 255, rand() % 255, rand() % 255);
}

Ball::Ball(const Ball & ball)
{
	center_.x = ball.getCenter().x;
	center_.y = ball.getCenter().y;
	radius_ = ball.getRadius();
	color_ = ball.getColor();
}

Point Ball::getCenter() const
{
	return center_;
}

int Ball::getRadius() const
{
	return radius_;
}

Ball & Ball::increaseRadius(int n)
{
	radius_ += n;
	return *this;
}

COLORREF Ball::getColor() const
{
	return color_;
}
