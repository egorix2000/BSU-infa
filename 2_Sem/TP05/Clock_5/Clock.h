#pragma once
class Clock {
private:
	int seconds_;
	int minutes_;
public:
	Clock();
	Clock(int seconds, int minutes);
	Clock(const Clock& clock);
	int getMinutes() const;
	int getSeconds() const;
	Clock& operator ++(int);
};

