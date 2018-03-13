#include "Questions.h"

Questions Question;

int main()
{
	Question.MakeChoice();
	Question.OpenFiles();
	Question.AssignVariables();
	Question.ChooseTest();

	return 0;
}
