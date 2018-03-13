#include "Questions.h"
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <windows.h>

Questions::Questions()
{

}

void Questions::MakeChoice()
{
	std::cout << "Do you want to do exercises from EVERY ETAP or ETAP WOJEWODZKI: " << std::endl;
	std::cout << "1. EVERY ETAP" << std::endl;
	std::cout << "2. ETAP WOJEWODZKI" << std::endl;
	std::cout << "Choice: ";
	std::cin >> Choice;
	system("CLS");
}

void Questions::OpenFiles()
{
	switch (Choice)
	{
	case 1:
	{
		quiz.open("quiz.txt", std::ios::in);
		if (quiz.good() == false)
		{
			std::cout << "Failed to load file";
			Sleep(2000);
			exit(0);
		}
		break;
	}
	case 2:
	{
		quiz2.open("quiz2.txt", std::ios::in);
		if (quiz.good() == false)
		{
			std::cout << "Failed to load file";
			Sleep(2000);
			exit(0);
		}
		break;
	}
	}
}

void Questions::AssignVariables()
{
	switch (Choice)
	{
	case 1:
	{
		while (std::getline(quiz, line))
		{
			switch (LineNumber) //LineNumber=1;
			{
			case 1: aText[QuestionNo] = line; break;
			case 2: aChoiceA[QuestionNo] = line; break;
			case 3: aChoiceB[QuestionNo] = line; break;
			case 4: aChoiceC[QuestionNo] = line; break;
			case 5: aChoiceD[QuestionNo] = line; break;
			case 6: aCorrectAnswer[QuestionNo] = line; break;
			}
			if (LineNumber == 6)
			{
				LineNumber = 0;
				QuestionNo++;
			}

			LineNumber++;
		}
		quiz.close();
		break;
	}
	case 2:
	{
		while (std::getline(quiz2, line))
		{
			switch (LineNumber) //LineNumber=1;
			{
			case 1: bText[QuestionNo] = line; break;
			case 2: bChoiceA[QuestionNo] = line; break;
			case 3: bChoiceB[QuestionNo] = line; break;
			case 4: bChoiceC[QuestionNo] = line; break;
			case 5: bChoiceD[QuestionNo] = line; break;
			case 6: bCorrectAnswer[QuestionNo] = line; break;
			}
			if (LineNumber == 6)
			{
				LineNumber = 0;
				QuestionNo++;
			}

			LineNumber++;
		}
		quiz2.close();
		break;
	}
	}
}

void Questions::AskSingleQuestions()
{
	srand(time(NULL));
	switch (Choice)
	{
	case 1:
	{
		RandomNumber = std::rand() % AmountOfQuestionsA + 1;
		std::cout << aText[RandomNumber] << std::endl;
		std::cout << "A) " << aChoiceA[RandomNumber] << std::endl;
		std::cout << "B) " << aChoiceB[RandomNumber] << std::endl;
		std::cout << "C) " << aChoiceC[RandomNumber] << std::endl;
		std::cout << "D) " << aChoiceD[RandomNumber] << std::endl;

		std::cout << "Choice: ";
		std::cin >> Answer;

		if (Answer == aCorrectAnswer[RandomNumber])
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
			std::cout << "The correct answer is " << aCorrectAnswer[RandomNumber] << "." << "\n";
			std::cout << "\n";
			std::cout << "Press enter to continue." << "\n";
			std::cin.get();
			std::cin.ignore();
			system("CLS");
		}
			break;
	}
	case 2:
	{
		RandomNumber = std::rand() % AmountOfQuestionsB + 1;
		std::cout << bText[RandomNumber] << std::endl;
		std::cout << "A) " << bChoiceA[RandomNumber] << std::endl;
		std::cout << "B) " << bChoiceB[RandomNumber] << std::endl;
		std::cout << "C) " << bChoiceC[RandomNumber] << std::endl;
		std::cout << "D) " << bChoiceD[RandomNumber] << std::endl;

		std::cout << "Choice: ";
		std::cin >> Answer;

		if (Answer == bCorrectAnswer[RandomNumber])
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
			std::cout << "The correct answer is " << bCorrectAnswer[RandomNumber] << "." << "\n";
			std::cout << "\n";
			std::cout << "Press enter to continue." << "\n";
			std::cin.get();
			std::cin.ignore();
			system("CLS");
		}
		break;
	}
	}
}

void Questions::AskWholeTest()
{
	std::cout << "How many questions would you like to do: ";
	int Amount;
	std::cin >> Amount;
	system("CLS");
	switch (Choice)
	{
	case 1:
	{
		for (int i = 0; i <= Amount - 1; i++)
		{
			srand(time(NULL));
			RandomNumber = std::rand() % AmountOfQuestionsA + 1;
			std::cout << aText[RandomNumber] << std::endl;
			std::cout << "A) " << aChoiceA[RandomNumber] << std::endl;
			std::cout << "B) " << aChoiceB[RandomNumber] << std::endl;
			std::cout << "C) " << aChoiceC[RandomNumber] << std::endl;
			std::cout << "D) " << aChoiceD[RandomNumber] << std::endl;

			std::cout << "Choice: ";
			std::cin >> Answer;

			if (Answer == aCorrectAnswer[RandomNumber])
			{
				Score += 1;
				std::cout << "Good answer!" << std::endl;
				std::cout << "Press enter to continue." << std::endl;
				std::cin.get();
				std::cin.ignore();
				system("CLS");
			}

			else
			{
				std::cout << "\n";
				std::cout << "Sorry, you're wrong..." << "\n";
				std::cout << "The correct answer is " << aCorrectAnswer[RandomNumber] << "." << "\n";
				std::cout << "\n";
				std::cout << "Press enter to continue." << std::endl;
				std::cin.get();
				std::cin.ignore();
				system("CLS");
			}
		}
		std::cout << "Your Total Score is " << Score << " out of " << Amount << "!" << std::endl;
		std::cout << "Its exactly: " << (Score * 100) / Amount << "%." << std::endl;
		std::cin.get();
		std::cin.get();
		break;
	}
	case 2:
	{
		for (int i = 0; i <= Amount - 1; i++)
		{
			srand(time(NULL));
			RandomNumber = std::rand() % AmountOfQuestionsB + 1;
			std::cout << bText[RandomNumber] << std::endl;
			std::cout << "A) " << bChoiceA[RandomNumber] << std::endl;
			std::cout << "B) " << bChoiceB[RandomNumber] << std::endl;
			std::cout << "C) " << bChoiceC[RandomNumber] << std::endl;
			std::cout << "D) " << bChoiceD[RandomNumber] << std::endl;

			std::cout << "Choice: ";
			std::cin >> Answer;

			if (Answer == bCorrectAnswer[RandomNumber])
			{
				Score += 1;
				std::cout << "Good answer!" << std::endl;
				std::cout << "Press enter to continue." << std::endl;
				std::cin.get();
				std::cin.ignore();
				system("CLS");
			}

			else
			{
				std::cout << "\n";
				std::cout << "Sorry, you're wrong..." << "\n";
				std::cout << "The correct answer is " << bCorrectAnswer[RandomNumber] << "." << "\n";
				std::cout << "\n";
				std::cout << "Press enter to continue." << std::endl;
				std::cin.get();
				std::cin.ignore();
				system("CLS");
			}
		}
		std::cout << "Your Total Score is " << Score << " out of " << Amount << "!" << std::endl;
		std::cout << "Its exactly: " << (Score * 100) / Amount << "%." << std::endl;
		std::cin.get();
		std::cin.get();
		break;
	}
	}
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
