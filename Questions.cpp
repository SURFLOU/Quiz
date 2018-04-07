#include "Questions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "random.hpp"

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
	Array.push_back(AmountOfQuestions());
	int i = 0;
	while (std::getline(Quiz, Line))
	{
		switch (LineNumber) //LineNumber=1;
		{
		case 1: Array[i].Text = Line; break;
		case 2: Array[i].ChoiceA = Line; break;
		case 3: Array[i].ChoiceB = Line; break;
		case 4: Array[i].ChoiceC = Line; break;
		case 5: Array[i].ChoiceD = Line; break;
		case 6: Array[i].CorrectAnswer = Line; break;
		}
		if (LineNumber == 6)
		{
			i++;
			Array.push_back(AmountOfQuestions());
			LineNumber = 0;
		}

		LineNumber++;
	}
	Quiz.close();
}

void Questions::AskSingleQuestions()
{
	auto RandomNumber = Random::get<int>(1, Array.size());
	std::cout << Array[RandomNumber].Text << std::endl;
	std::cout << "A) " << Array[RandomNumber].ChoiceA << std::endl;
	std::cout << "B) " << Array[RandomNumber].ChoiceB << std::endl;
	std::cout << "C) " << Array[RandomNumber].ChoiceC << std::endl;
	std::cout << "D) " << Array[RandomNumber].ChoiceD << std::endl;

	std::cout << "Choice: ";
	std::cin >> Answer;

	if (Answer == Array[RandomNumber].CorrectAnswer)
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
		std::cout << "The correct answer is " << Array[RandomNumber].CorrectAnswer << "." << "\n";
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
		auto RandomNumber = Random::get<int>(1, Array.size());
		std::cout << Array[RandomNumber].Text << std::endl;
		std::cout << "A) " << Array[RandomNumber].ChoiceA << std::endl;
		std::cout << "B) " << Array[RandomNumber].ChoiceB << std::endl;
		std::cout << "C) " << Array[RandomNumber].ChoiceC << std::endl;
		std::cout << "D) " << Array[RandomNumber].ChoiceD << std::endl;

		std::cout << "Choice: ";
		std::cin >> Answer;

		if (Answer == Array[RandomNumber].CorrectAnswer)
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
