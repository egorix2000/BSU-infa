#include "Light.h"

int Light::getTime() const {
	return time_;
}

COLORREF Light::getMainColor() const {
	return mainColor_;
}

COLORREF Light::getDarkColor() const {
	return darkColor_;
}

color Light::getType() const {
	return type_;
}

bool Light::getIsFlickerSize() const
{
	return isFlickerSize_;
}

void Light::switchIsFlickerSize()
{
	isFlickerSize_ = !isFlickerSize_;
}

void Light::setIsFlickerSize(bool isFlickerSize)
{
	isFlickerSize_ = isFlickerSize;
}
