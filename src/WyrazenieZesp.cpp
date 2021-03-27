#include "WyrazenieZesp.hh"
#include <iostream>
using namespace std;
/*Wyczytywanie wyrazenia zespolonego. Do tego celu potrzebne jest przesuniecie operatora bitowego w lewo dla liczby zespolonej. 
Za jej pomocą operator bitowy przesuniecia bitowego w lewo dla wyrazenia wyczytuje liczby zespolone, 
za pomocą funcji switch wczytuje operator okreslony w funkcji Operator*/

ostream &operator<<(ostream &StrWyj, const WyrazenieZesp &WyrZ)
{
    StrWyj << (WyrZ.Arg1);
    switch (WyrZ.Op)
    {
    case Op_Dodaj:
        StrWyj << "+";
        break;
    case Op_Odejmij:
        StrWyj << "-";
        break;
    case Op_Mnoz:
        StrWyj << "*";
        break;
    case Op_Dziel:
        StrWyj << "/";
        break;
    }
    StrWyj << (WyrZ.Arg2);
    return StrWyj;
}
/*Wczytywanie wyrazenia zespolonego. Do tego celu potrzebne jest przesuniecie operatora bitowego w prawo dla liczby zespolonej. 
Za jej pomocą operator bitowy przesuniecia bitowego w prawo dla wyrazenia wczytuje liczby zespolone, 
za pomocą funcji switch wczytuje operator okreslony w funkcji Operator*/

istream &operator>>(istream &StrWe, WyrazenieZesp &WyrZ)
{
    char znak;
    StrWe >> (WyrZ.Arg1);
    StrWe >> znak;
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
    default:
        StrWe.setstate(ios::failbit);
        break;
    }
    StrWe >> WyrZ.Arg2;
    return StrWe;
}
/*Funkcja wykonuje odpowiednie działanie dla zadanego operatora*/
LZespolona WyrazenieZesp::Oblicz()
{
    LZespolona wynik;
    switch (this->Op)
    {
    case Op_Dodaj:
        wynik = this->Arg1 + this->Arg2;
        break;
    case Op_Odejmij:
        wynik = this->Arg1 - this->Arg2;
        break;
    case Op_Mnoz:
        wynik = this->Arg1 * this->Arg2;
        break;
    case Op_Dziel:
        wynik = this->Arg1 / this->Arg2;
        break;
    }
    return wynik;
}
