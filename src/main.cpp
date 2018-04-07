#include "Questions.h"

Questions Question;

int main()
{
	Question.OpenFile();
	Question.AssignVariables();
	Question.ChooseTest();

	return 0;
}
