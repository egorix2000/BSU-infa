#include "answerform.h"

AnswerForm::AnswerForm()
{
    //ctor
}
AnswerForm::AnswerForm(int amountOfQuestions)
{
    answers = new bool*[amountOfQuestions];
    for(int i = 0; i < amountOfQuestions; i++){
        answers[i] = new bool[5];
        for(int j = 0; j < 5; j++){
            answers[i][j] = false;
        }
    }
}
UINT AnswerForm::getCheckState(int question_id, int answer_id){
    return ((answers[question_id][answer_id]) ? BST_CHECKED : BST_UNCHECKED);
}
void AnswerForm::addAnswer(int question_id, int answer_id, bool value){
    answers[question_id][answer_id] = value;
}
double AnswerForm::getResult(Poll poll){
    double result = 0;
	double questionPoints;
	double correctAnswers;
	double userCorrectAnswers;
    for(int i = 0; i < poll.questions.size(); i++){
		questionPoints = poll.questions[i].points;
		correctAnswers = 0;
		userCorrectAnswers = 0;
        for(int j = 0; j < poll.questions[i].answers.size(); j++){
			if (poll.questions[i].answers[j].correct) {
				correctAnswers++;
			}
			if (answers[i][j] && poll.questions[i].answers[j].correct) {
				userCorrectAnswers++;
			}
			else if (answers[i][j] && !poll.questions[i].answers[j].correct) {
				userCorrectAnswers--;
			}
        }
		if (userCorrectAnswers < 0) {
			userCorrectAnswers = 0;
		}
        result += questionPoints * (userCorrectAnswers / correctAnswers);
    }
    return result;
}
