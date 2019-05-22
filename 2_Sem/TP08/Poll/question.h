#pragma once
#include "answer.h"
#include <string>
#include <vector>
#include <sstream>
enum QuestionType{
    OneAnswer,
    MultipleAnswer
};
class Question
{
    public:
        Question();
        QuestionType type;
        std::string text;
		double points;
        std::vector<Answer> answers;
};
