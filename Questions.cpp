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
	quiz.open("quiz.txt", std::ios::in);
	if (quiz.good() == false)
	{
		std::cout << "Failed to load file";
		Sleep(2000);
		exit(0);
	}
	
}

void Questions::AssignVariables()
{
	while (std::getline(quiz, line))
	{
		switch (LineNumber) //LineNumber=1;
		{
		case 1: Text[QuestionNo] = line; break;
		case 2: ChoiceA[QuestionNo] = line; break;
		case 3: ChoiceB[QuestionNo] = line; break;
		case 4: ChoiceC[QuestionNo] = line; break;
		case 5: ChoiceD[QuestionNo] = line; break;
		case 6: CorrectAnswer[QuestionNo] = line; break;
		}
		if (LineNumber == 6)
		{
			LineNumber = 0;
			QuestionNo++;
		}

		LineNumber++;
	}
	quiz.close();
}

void Questions::AskSingleQuestions()
{
	srand(time(NULL));
	RandomNumber = std::rand() % AmountOfQuestions + 1;
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
	for (int i = 0; i <= 29; i++)
	{
		srand(time(NULL));
		RandomNumber = std::rand() % AmountOfQuestions + 1;
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
	std::cout << "Your Total Score is " << Score << " out of 30!" << std::endl;
	std::cout << "Its exactly: " << (Score * 100) / 30 << " percentage" << std::endl;
	std::cin.get();
	std::cin.get();
}

void Questions::ChooseTest()
{
	std::cout << "Do you want single questions or whole test?" << std::endl;
	std::cout << "1. single questions" << std::endl;
	std::cout << "2. whole test" << std::endl;
	std::cout << "Choice: ";

	int choice;
	std::cin >> choice;
	system("CLS");

	switch (choice)
	{
	case 1: 
		{
		while (!GetAsyncKeyState == VK_DELETE)
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
