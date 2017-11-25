#include <iostream>
#include "Questions.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>



Questions q[100]; //[100] = amount of questions q = question

void SetAllValues();

int main()
{
      SetAllValues();
      srand(time(NULL));
      while(!GetAsyncKeyState(VK_DELETE))
      {
          q[(std::rand() % 7 ) + 0].askQuestions();
      }

    return 0;
}
void SetAllValues()
{
    q[0].setValues("Ktory z ponizszych elementow nie jest elementem plyty glownej?",
        "Procesor lub gniazdo do jego instalacji ",
        "Pendrive lub karta SD ",
        "Pamiec operacyjna lub gniazdo do jej instalacji ",
        "Gniazdo do dysku twardego ",
        'b');
    q[1].setValues("Ktore z ponizszych zdan nie charakteryzuje procesora?",
        "Procesor to zlozony element elektroniczny, zdolny do wykonywania operacji matematycznych wedlug dostarczonych mu instrukcji.",
        "Procesor nazywany jest rowniez centralna jednostka obliczeniowa (CPU, ang. Central Processing Unit). ",
        "Czestotliwosc taktowania procesora wyraza sie w voltach",
        "Czestotliwosc taktowania moze sie zmieniac w trakcie pracy procesora",
        'c');
     q[2].setValues("Ktory z ponizszych elementow nie jest karta rozszerzen?",
        "Karta modemu wewnetrznego.",
        "Karta sieciowa",
        "Karta pamieci",
        "Karta dzwiekowa ",
        'c');
     q[3].setValues("Co jest najmniejsza jednostka informacji?",
        "1 bajt",
        "1 mit",
        "1 pit",
        "1 bit",
        'd');
     q[4].setValues("Do pamieci wewnetrznych nie nalezy:",
        "Floppy disk",
        "Read Only Memory",
        "Random Access Memory ",
        "Nie ma poprawnej odpowiedzi",
        'a');
      q[5].setValues("Ktore z ponizszych zdan nie charakteryzuje pamieci ROM?",
        "ROM jest to pamiec tylko do odczytu.",
        "Dane zapisane w ROM sa ulotne i gina, gdy tylko zasilanie jest wylaczone.",
        "ROM umozliwia rozpoczecie pracy komputera, rozruch poszczegolnyc podzespolow i wspolprace mikroprocesora z pozostalymi czesciami zestawukomputerowego. ",
        "Zawartosc pamieci ROM nie zalezy od uzytkownika.",
        'a');
      q[6].setValues("Ktore z ponizszych zdan nie charakteryzuje pamieci RAM?",
        "RAM to pamiec o dostepie swobodnym.",
        "Procesor wczytuje do niej program przed jego wykonaniem oraz przechowuje wyniki swoich obliczen.",
        "Pamiec ta przechowuje informacje nawet po wylaczeniu pradu.",
        "Nie ma poprawnej odpowiedzi",
        'c');

}

