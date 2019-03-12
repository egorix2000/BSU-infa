#include "Day.h"



Day::Day()
{
	dayName_ = "";
}

Day::Day(std::string dayName)
{
	dayName_ = dayName;
}

void Day::addLesson(const Lesson & lesson)
{
	lessons_.push_back(Lesson(lesson));
}

std::string Day::getDayName() const
{
	return dayName_;
}

void Day::setDayName(std::string dayName)
{
	dayName_ = dayName;
}

int Day::getNumberOfLessons() const
{
	return lessons_.size();
}

void Day::clear()
{
	dayName_ = "";
	lessons_.clear();
}

Lesson & Day::operator[](int index)
{
	return lessons_[index];
}
