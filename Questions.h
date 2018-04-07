#pragma once
#include <fstream>
#include <vector>
#include "random.hpp"


class Questions
{
public:
	Questions();
	~Questions();


protected:
	std::fstream Quiz;

protected:
	struct AmountOfQuestions
	{
		std::string Text;
		std::string ChoiceA;
		std::string ChoiceB;
		std::string ChoiceC;
		std::string ChoiceD;
		std::string CorrectAnswer;
	};

protected:
	int LineNumber = 1;
	int QuestionNo = 0; //Question Number
	int Score;

protected:
	std::vector<AmountOfQuestions> Array;

protected:
	std::string Answer;
	std::string Line;

protected:
	using Random = effolkronium::random_static;

public:
	void OpenFile();
	void AssignVariables();
	void ChooseTest();
	void AskSingleQuestions();
	void AskWholeTest();




};
