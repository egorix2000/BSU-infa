#include "Ball.h"
#include "Point.h"
#include <windows.h>

Ball::Ball()
{
	center_.x = 0;
	center_.y = 0;
	radius_ = 0;
}

Ball::Ball(Point &center, int radius)
{
	center_ = center;
	radius_ = radius;
	color_ = RGB(rand() % 255, rand() % 255, rand() % 255);
}

Ball::Ball(const Ball & ball)
{
	center_ = ball.getCenter();
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

Ball & Ball::operator=(const Ball & ball)
{
	center_ = ball.getCenter();
	radius_ = ball.getRadius();
	color_ = ball.getColor();
	return *this;
}

bool operator==(const Ball & ballLeft, const Ball & ballRight)
{
	return ballLeft.center_ == ballRight.center_;
}
