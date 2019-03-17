#pragma once

#include <windows.h>

enum color {RED, YELLOW, GREEN};

class Light {
protected:
	int time_;
	color type_;
	COLORREF mainColor_;
	COLORREF darkColor_;
	bool isFlickerSize_;
public:
	Light(int time) : time_(time) { isFlickerSize_ = false; };
	virtual ~Light() {};
	int getTime() const;
	COLORREF getMainColor() const;
	COLORREF getDarkColor() const;
	color getType() const;
	bool getIsFlickerSize() const;
	void switchIsFlickerSize();
	void setIsFlickerSize(bool isFlickerSize);
};