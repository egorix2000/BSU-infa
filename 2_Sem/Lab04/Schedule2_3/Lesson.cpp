#include "Lesson.h"



Lesson::Lesson()
{
	lessonType_ = "";
	subject_ = "";
	auditorium_ = "";
}

Lesson::Lesson(std::string lessonType, std::string subject, std::string auditorium)
{
	lessonType_ = lessonType;
	subject_ = subject;
	auditorium_ = auditorium;
}

Lesson::Lesson(const Lesson & lesson)
{
	lessonType_ = lesson.getLessonType();
	subject_ = lesson.getSubject();
	auditorium_ = lesson.getAuditorium();
}

std::string Lesson::getLessonType() const
{
	return lessonType_;
}

std::string Lesson::getSubject() const
{
	return subject_;
}

std::string Lesson::getAuditorium() const
{
	return auditorium_;
}

void Lesson::setLessonType(std::string lessonType)
{
	lessonType_ = lessonType;
}

void Lesson::setSubject(std::string subject)
{
	subject_ = subject;
}

void Lesson::setAuditorium(std::string auditorium)
{
	auditorium_ = auditorium;
}
