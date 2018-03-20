#include "Questions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>

Questions::Questions()
{

}

void Questions::OpenFile()
{
	Quiz.open("quiz.txt", std::ios::in);
	if (Quiz.good() == false)
	{
		std::cout << "Failed to load file";
		std::cin.get();
		std::cin.get();
		exit(0);
	}

}

void Questions::AssignVariables()
{
	while (std::getline(Quiz, Line))
	{
		switch (LineNumber) //LineNumber=1;
		{
		case 1: Text[QuestionNo] = Line; break;
		case 2: ChoiceA[QuestionNo] = Line; break;
		case 3: ChoiceB[QuestionNo] = Line; break;
		case 4: ChoiceC[QuestionNo] = Line; break;
		case 5: ChoiceD[QuestionNo] = Line; break;
		case 6: CorrectAnswer[QuestionNo] = Line; break;
		}
		if (LineNumber == 6)
		{
			LineNumber = 0;
			QuestionNo++;
		}

		LineNumber++;
	}
	Quiz.close();
}

void Questions::AskSingleQuestions()
{
	srand(time(NULL));
	RandomNumber = rand() % AmountOfQuestions + 1;
	std::cout << Text[RandomNumber] << std::endl;
	std::cout << "A) " << ChoiceA[RandomNumber] << std::endl;
	std::cout << "B) " << ChoiceB[RandomNumber] << std::endl;
	std::cout << "C) " << ChoiceC[RandomNumber] << std::endl;
	std::cout << "D) " << ChoiceD[RandomNumber] << std::endl;

	std::cout << "Choice: ";
	std::cin >> Answer;

	if (Answer == CorrectAnswer[RandomNumber])
	{
		std::cout << "\n";
		std::cout << "Correct Answer!" << std::endl;
		std::cin.get();
		std::cin.ignore();
		system("CLS");
	}

	else
	{
		std::cout << "\n";
		std::cout << "Sorry, you're wrong..." << "\n";
		std::cout << "The correct answer is " << CorrectAnswer[RandomNumber] << "." << "\n";
		std::cout << "\n";
		std::cout << "Press enter to continue." << "\n";
		std::cin.get();
		std::cin.ignore();
		system("CLS");
	}
}

void Questions::AskWholeTest()
{
	std::cout << "How many questions would you like to do: ";
	int Amount;
	std::cin >> Amount;
	system("CLS");

	for (int i = 0; i <= Amount - 1; i++)
	{
		srand(time(NULL));
		RandomNumber = rand() % AmountOfQuestions + 1;
		std::cout << Text[RandomNumber] << std::endl;
		std::cout << "A) " << ChoiceA[RandomNumber] << std::endl;
		std::cout << "B) " << ChoiceB[RandomNumber] << std::endl;
		std::cout << "C) " << ChoiceC[RandomNumber] << std::endl;
		std::cout << "D) " << ChoiceD[RandomNumber] << std::endl;

		std::cout << "Choice: ";
		std::cin >> Answer;

		if (Answer == CorrectAnswer[RandomNumber])
		{
			Score += 1;
			std::cout << "Press enter to continue." << std::endl;
			std::cin.get();
			std::cin.ignore();
			system("CLS");
		}

		else
		{
			std::cout << "Press enter to continue." << std::endl;
			std::cin.get();
			std::cin.ignore();
			system("CLS");
		}
	}
	std::cout << "Your Total Score is " << Score << " out of " << Amount << "!" << std::endl;
	std::cout << "Its exactly: " << (Score * 100) / Amount << " percentage" << std::endl;
	std::cin.get();
	std::cin.get();
}

void Questions::ChooseTest()
{
	std::cout << "Do you want single questions or whole test?" << std::endl;
	std::cout << "1. single questions" << std::endl;
	std::cout << "2. whole test" << std::endl;
	std::cout << "Choice: ";

	int Choice;
	std::cin >> Choice;
	system("CLS");

	switch (Choice)
	{
	case 1:
	{
		while (true)
		{
			AskSingleQuestions();
		}
		break;
	}
	case 2:
	{
		AskWholeTest();
		break;
	}
	}
}

Questions::~Questions()
{

}
