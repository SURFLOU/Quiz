#include "Questions.h"
#include <windows.h>


Questions::Questions()
{

}

void Questions::setValues(std::string q, std::string a1, std::string a2, std::string a3, std::string a4, char ca)
{
    questionText = q;
    Option1 = a1;
    Option2 = a2;
    Option3 = a3;
    Option4 = a4;
    correctAnswer = ca;
}
//Format for possible answers displayed when program executes.
void Questions::askQuestions()
{
    std::cout << questionText << std::endl;
    std::cout<<"\n";
    std::cout << "a. " << Option1 << "\n";
    std::cout << "b. " << Option2 << "\n";
    std::cout << "c. " << Option3 << "\n";
    std::cout << "d. " << Option4 << "\n";
    std::cout << "\n";


    std::cout << "What is your answer: ";
    std::cin >> guess;

    if (guess == correctAnswer) {
        std::cout << "\n";
        std::cout << "Correct!" << "\n";
        std::cout << "Press enter to continue." << "\n";
        std::cin.get();
        std::cin.ignore();
        system("CLS");
    }
    else
    {
        std::cout << "\n";
        std::cout << "Sorry, you're wrong..." << "\n";
        std::cout << "The correct answer is " << correctAnswer << "." << "\n";
        std::cout << "\n";
        std::cout << "Press enter to continue." << "\n";
        std::cin.get();
        std::cin.ignore();
        system("CLS");
    }
}

Questions::~Questions()
{

}
