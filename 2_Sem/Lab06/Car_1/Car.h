#pragma once

#define FORWARD 1
#define BACKWARD 2

class Car
{
private:
	int x_;
	int y_;
	int width_;
	int height_;
	int speed_; // pixels per second
	int direction_; // mode
public:
	Car();
	Car(int x, int y, int speed, int direction, int width, int height);
	Car(const Car& source);
	int getX() const;
	int getY() const;
	int getWidth() const;
	int getHeight() const;
	int getSpeed() const;
	int getDirection() const;
	void setX(int x);
	void setY(int y);
	void setWidth(int width);
	void setHeight(int height);
	void setSpeed(int speed);
	void setDirection(int direction);
	void changeDirection();
	Car& move(int x);
};

