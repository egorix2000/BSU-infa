#pragma once
class Clock
{
private:
	int seconds_;
	bool isActive_;
public:
	Clock();
	int getSeconds() const;
	bool getIsActive() const;
	void setIsActive(bool isActive);
	void setSeconds(int seconds);
	Clock& operator ++(int);
};

