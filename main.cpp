#include <iostream>
#include "Questions.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>



Questions q[100]; //[100] = amount of questions q = question

void SetAllValues();

int main()
{
      srand(time(NULL));
      SetAllValues();
      while(!GetAsyncKeyState(VK_DELETE))
      {
          q[(std::rand() % 1 ) + 0].askQuestions();
      }

    return 0;
}
void SetAllValues()
{
    q[0].setValues("Czy dodajemy marcela na konfe?",
        "tak",
        "nie",
        "jasne",
        "czemu nie",
        'b');
}
