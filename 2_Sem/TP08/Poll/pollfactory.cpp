#include "pollfactory.h"

bool isCorrectInputFile(std::ifstream &_fin) {
    bool res = true;
    if(!_fin){
        std::cout << "Input file doesn't exist" << std::endl;
        res =  false;
    } else if(_fin.peek() == std::ifstream::traits_type::eof()){
        std::cout << "Input file is empty" << std::endl;
        res = false;
    }
    return res;
}

bool verifyQuestions(Poll &poll) {
    int answerCounter = 0;
    bool result = poll.questions.size() > 0;
    for(int i = 0; i < poll.questions.size() && result; i++){
        int ansNum = poll.questions[i].answers.size();
        if(ansNum < 2 || ansNum > 5){
            result = false;
            break;
        }
        for(int j = 0; j < poll.questions[i].answers.size(); j++){
            answerCounter += ((int) poll.questions[i].answers[j].correct);
        }
        if(answerCounter == 0){
            result = false;
        }
    }
    return result;
}

void clearQuestion(Question & question){
    question.answers.clear();
    question.text = "";
    question.type = QuestionType::OneAnswer;
}

void clearAnswer(Answer &answer){
    answer = Answer("", false);
}

void readFile(std::ifstream &fin, Poll &poll, bool &fail){
    std::string s;
	Question question;
	Answer ans;
	(getline(fin, s));
	poll.header = s;
	while (getline(fin, s)) {
		switch (s[0]) {
		case '#': {
			clearQuestion(question);
			getline(fin, s);
			question.points = atoi(s.c_str());
			getline(fin, s);
			if (s == "One") {
				question.type = OneAnswer;
			}
			else {
				question.type = MultipleAnswer;
			}
			getline(fin, s);
			question.text = s;
			getline(fin, s);
			while (s != "#") {
				clearAnswer(ans);
				ans.statement = s;
				getline(fin, s);
				if (s == "+") {
					ans.correct = true;
				}
				else {
					ans.correct = false;
				}
				question.answers.push_back(ans);
				getline(fin, s);
			}
			poll.questions.push_back(question);
		}
		case '\n':
			break;
		default:
			fail = true;
			break;
		}
	}
}
bool PollFactory::InitPoll(Poll &poll, std::string filename){
    poll.questions.clear();
    bool fail = false;
    std::ifstream fin(filename);
    if(isCorrectInputFile(fin)){
		readFile(fin, poll, fail);
        if(!verifyQuestions(poll))
			fail = true;
    } else {
        fail = true;
    }
    return !fail;
}
