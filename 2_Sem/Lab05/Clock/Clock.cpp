#include "Clock.h"



Clock::Clock()
{
	seconds_ = 0;
	isActive_ = true;
}

int Clock::getSeconds()
{
	return seconds_;
}

bool Clock::getIsActive()
{
	return isActive_;
}

void Clock::setIsActive(bool isActive)
{
	isActive_ = isActive;
}

void Clock::setSeconds(int seconds)
{
	seconds_ = seconds;
}

Clock & Clock::operator++(int)
{
	seconds_++;
	return *this;
}
