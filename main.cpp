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
          q[(std::rand() % 18 ) + 0].askQuestions();
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
       q[7].setValues("Szybkosc 128 B/s to inaczej?",
        "1024 b/s",
        "8 kB/s",
        "1024 kB/s",
        "128 b/s ",
        'a');
       q[8].setValues("Ktore z ponizszych zdan nie charakteryzuje dysku twardego?",
        "Dysk twardy inaczej Hard Disk Drive - HDD.",
        "Dysk twardy sluzy do przechowywania programow, danych i wynikow pracy komputera.",
        "Dyski moga byc montowane tylko wewnatrz komputera. ",
        "Zawartosc dysku twardego nie znika po wylaczeniu zasilania",
        'c');
       q[9].setValues("Ktory z ponizszych nosnikow nie jest napedem optycznym?",
        "DVD DL",
        "DVD TL",
        "CD-RW",
        "BD",
        'b');
       q[10].setValues("Ktore z ponizszych zdan nie charakteryzuje urzadzenia peryferyjnego?",
        "Urzadzenie peryferyjne to urzadzenie znajdujace sie poza obudowa komputera.",
        "Urzadzenie peryferyjne to urzadzenie znajdujace sie wewnatrz komputera.",
        "Urzadzenie to umozliwia wspolprace miedzy uzytkownikiem a komputerem,zwlaszcza w zakresie wprowadzania, przetwarzania i modyfikacji danych",
        "Nie ma prawidlowej odpowiedzi",
        'b');
       q[11].setValues("Ktore z ponizszych zdan nie charakteryzuje sterownika?",
        "Sterownik danego urzadzenia nalezy zainstalowac zaraz po pierwszym uzyciu tego urzadzenia.",
        "Sterownik to z jezyka angielskiego driver",
        "Sterownik to program odpowiedzialny za prawidlowe funkcjonowanie urzadzen komputera.",
        "Nie ma prawidlowej odpowiedzi",
        'a');
       q[12].setValues("Ktore z ponizszych urzadzen peryferyjnych jest urzadzeniem wejsciowym",
        "Monitor",
        "Skaner",
        "Ploter",
        "Nie ma prawidlowej odpowiedzi",
        'b');
       q[13].setValues("Interfejsem do podlaczania dysku twardego nie jest:",
        "SATA",
        "ATA",
        "USB",
        "RS-232C",
        'd');
       q[14].setValues("Myszki nie podlaczysz do portu:",
        "PS/2",
        "USB",
        "LPT",
        "Nie ma prawidlowej odpowiedzi",
        'c');
       q[15].setValues("Ktore z ponizszych zdan nie charakteryzuje systemu operacyjnego?",
        "System operacyjny nie organizuje sposobu zapisu i odczytu plikow na dysku",
        "System operacyjny zapewnia obsluge urzadzen peryferyjnych",
        "System operacyjny steruje instalowaniem i uruchamianiem innych programow.",
        "Nie ma prawidlowej odpowiedzi",
        'a');
       q[16].setValues("Ktore z ponizszych zdan nie charakteryzuje pliku?",
        "Plik to zapisany w pamieci masowej komputera zbior danych o okreslonym rozmiarze i stanowiacym logiczna calosc.",
        "Każdy plik musi mieć niepowtarzalną nazwę w danym komputerze.",
        "Plikiem jest zarowno dokument tekstowy, jak i graficzny.",
        "Nie ma prawidlowej odpowiedzi",
        'b');
       q[17].setValues("Ktore z ponizszych zdań nie charakteryzuje folderu?",
        "Folder mozemy inaczej nazywac katalogiem.",
        "Folder to pewien logiczny obiekt, ulatwiajacy organizacje plikow na nosnikach pamieci.",
        "Folder moze zawierac tylko pliki",
        "Nie ma prawidlowej odpowiedzi",
        'c');
       q[17].setValues("Ktore z ponizszych zdań nie charakteryzuje folderu?",
        "Folder mozemy inaczej nazywac katalogiem.",
        "Folder to pewien logiczny obiekt, ulatwiajacy organizacje plikow na nosnikach pamieci.",
        "Folder moze zawierac tylko pliki",
        "Nie ma prawidlowej odpowiedzi",
        'c');


}

