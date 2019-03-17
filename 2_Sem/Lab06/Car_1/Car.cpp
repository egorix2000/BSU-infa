#include "Car.h"


Car::Car()
{
	x_ = 0;
	y_ = 0;
	speed_ = 0;
	width_ = 0;
	height_ = 0;
}

Car::Car(int x, int y, int speed, int direction, int width, int height) {
	x_ = x;
	y_ = y;
	speed_ = speed;
	direction_ = direction;
	width_ = width;
	height_ = height;
}

Car::Car(const Car & source)
{
	x_ = source.getX();
	y_ = source.getY();
	speed_ = source.getSpeed();
	direction_ = source.getDirection();
	width_ = source.getWidth();
	height_ = source.getHeight();
}

int Car::getX() const {
	return x_;
}

int Car::getY() const {
	return y_;
}

int Car::getWidth() const
{
	return width_;
}

int Car::getHeight() const
{
	return height_;
}

int Car::getSpeed() const {
	return speed_;
}

int Car::getDirection() const
{
	return direction_;
}

void Car::setX(int x) {
	x_ = x;
}

void Car::setY(int y) {
	y_ = y;
}

void Car::setWidth(int width)
{
	width_ = width;
}

void Car::setHeight(int height)
{
	height_ = height;
}

void Car::setSpeed(int speed)
{
	speed_ = speed;
}

void Car::setDirection(int direction)
{
	direction_ = direction;
}

void Car::changeDirection()
{
	if (direction_ == 1) {
		direction_ = 2;
	}
	else {
		direction_ = 1;
	}
}

Car & Car::operator+=(int x)
{
	x_ += x;
	return *this;
}

Car & Car::operator-=(int x)
{
	x_ -= x;
	return *this;
}
