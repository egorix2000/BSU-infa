#include "Clock.h"



Clock::Clock()
{
}

Clock::Clock(int seconds, int minutes)
{
	seconds_ = seconds;
	minutes_ = minutes;
}

Clock::Clock(const Clock & clock)
{
	seconds_ = clock.getSeconds();
	minutes_ = clock.getMinutes();
}

int Clock::getMinutes() const
{
	return minutes_;
}

int Clock::getSeconds() const
{
	return seconds_;
}

Clock & Clock::operator++(int)
{
	seconds_++;
	if (seconds_ >= 60) {
		seconds_ = 0;
		minutes_++;
	}
	if (minutes_ >= 60) {
		minutes_ = 0;
	}
	return *this;
}
