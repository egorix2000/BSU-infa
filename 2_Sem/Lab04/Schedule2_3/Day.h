#pragma once

#include <vector>
#include <string>
#include "Lesson.h"

class Day
{
private:
	std::string dayName_;
	std::vector<Lesson> lessons_;
public:
	Day();
	Day(std::string dayName);
	void addLesson(const Lesson &lesson);
	std::string getDayName() const;
	void setDayName(std::string dayName);
	int getNumberOfLessons() const;
	void clear();
	Lesson& operator [](int index);
};

