#pragma once
#include <fstream>


class Questions
{
public:
	Questions();
	~Questions();


protected:
	std::fstream Quiz;

protected:
	int LineNumber = 1;
	int QuestionNo = 0; //Question Number
	int static const AmountOfQuestions = 188;
	int RandomNumber;
	int Score;

protected:
	std::string Text[AmountOfQuestions];
	std::string ChoiceA[AmountOfQuestions];
	std::string ChoiceB[AmountOfQuestions];
	std::string ChoiceC[AmountOfQuestions];
	std::string ChoiceD[AmountOfQuestions];
	std::string CorrectAnswer[AmountOfQuestions];
	std::string Answer;
	std::string Line;

public:
	void OpenFile();
	void AssignVariables();
	void ChooseTest();
	void AskSingleQuestions();
	void AskWholeTest();



};
