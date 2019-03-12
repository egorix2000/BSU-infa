#pragma once

#include <string>

class Lesson
{
private:
	std::string lessonType_;
	std::string subject_;
	std::string auditorium_;
public:
	Lesson();
	Lesson(std::string lessonType, std::string subject, std::string auditorium);
	Lesson(const Lesson& lesson);
	std::string getLessonType() const;
	std::string getSubject() const;
	std::string getAuditorium() const;
	void setLessonType(std::string lessonType);
	void setSubject(std::string subject);
	void setAuditorium(std::string auditorium);
};

