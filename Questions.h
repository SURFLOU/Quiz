#pragma once
#include <fstream>


class Questions
{
public:
	Questions();
	~Questions();


protected:	
	std::fstream quiz;
	std::fstream quiz2;

protected:
	int LineNumber = 1;
	int QuestionNo = 0;
	int static const AmountOfQuestionsA = 188;
	int static const AmountOfQuestionsB = 50;
	int RandomNumber;
	int Score;
	int Choice;

protected:
	std::string aText[AmountOfQuestionsA], bText[AmountOfQuestionsB];
	std::string aChoiceA[AmountOfQuestionsA], bChoiceA[AmountOfQuestionsB];
	std::string aChoiceB[AmountOfQuestionsA], bChoiceB[AmountOfQuestionsB];
	std::string aChoiceC[AmountOfQuestionsA], bChoiceC[AmountOfQuestionsB];
	std::string aChoiceD[AmountOfQuestionsA], bChoiceD[AmountOfQuestionsB];
	std::string aCorrectAnswer[AmountOfQuestionsA], bCorrectAnswer[AmountOfQuestionsB];
	std::string Answer;
	std::string line;

public:
	void OpenFiles();
	void AssignVariables();
	void ChooseTest();
	void AskSingleQuestions();
	void AskWholeTest();
	void MakeChoice();

};

