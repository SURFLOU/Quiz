#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <iostream>


class Questions
{
    public:
        Questions();
        ~Questions();


        void setValues(std::string q, std::string a1, std::string a2, std::string a3, std::string a4, char ca);
        void askQuestions();


    protected:

        std::string questionText;
        std::string Option1;
        std::string Option2;
        std::string Option3;
        std::string Option4;

        char correctAnswer;
        int questionScore;
        char guess;

    private:


};

#endif // QUESTIONS_H
