#include "WyrazenieZesp.hh"
#include <iostream>
using namespace std;
/*Wyświetlanie wyrazenia zespolonego. Do tego celu potrzebna była funkcja Wywietl dla liczby zespolonej. 
Za jej pomocą funkcja Wyswietl dla wyrazenia wczytuje liczby zespolone, za pomocą funcji switch wyswietla operator okreslony w funkcji Operator*/

void Wyswietl(WyrazenieZesp WyrZ)
{
    Wyswietl(WyrZ.Arg1);
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        cout << "+";
        break;
    case Op_Odejmij:
        cout << "-";
        break;
    case Op_Mnoz:
        cout << "*";
        break;
    case Op_Dziel:
        cout << "/";
        break;
    }
    Wyswietl(WyrZ.Arg2);
}
/*Wczytywanie wyrazenia zespolonego. Do tego celu potrzebna była funkcja Wczytaj dla liczby zespolonej. 
Za jej pomocą funkcja Wczytaj dla wyrazenia wczytuje liczby zespolone, za pomocą funcji switch wczytuje operator okreslony w funkcji Operator*/

void Wczytaj(WyrazenieZesp &WyrZ)
{
    char znak;
    Wczytaj(WyrZ.Arg1);
    cin >> znak;
    switch (znak)
    {
    case '+':
        WyrZ.Op = Op_Dodaj;
        break;
    case '-':
        WyrZ.Op = Op_Odejmij;
        break;
    case '*':
        WyrZ.Op = Op_Mnoz;
        break;
    case '/':
        WyrZ.Op = Op_Dziel;
        break;
    }
Wczytaj(WyrZ.Arg2);
}
/*Funkcja wykonuje odpowiednie działanie dla zadanego operatora*/
LZespolona Oblicz(WyrazenieZesp WyrZ)
{
    LZespolona wynik;
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        wynik = WyrZ.Arg1 + WyrZ.Arg2;
        break;
    case Op_Odejmij:
        wynik = WyrZ.Arg1 - WyrZ.Arg2;
        break;
    case Op_Mnoz:
        wynik = WyrZ.Arg1 * WyrZ.Arg2;
        break;
    case Op_Dziel:
        wynik = WyrZ.Arg1 / WyrZ.Arg2;
        break;
    }
    return wynik;
}
