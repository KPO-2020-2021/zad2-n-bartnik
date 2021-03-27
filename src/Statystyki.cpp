#include "Statystyki.hh"
#include <iostream>

/*FUnkcja zeruje kazda zmienna w strukturze Statystyka. Jest to potrzebne do prawidłowego zliczania punktów*/
void Statystyka::Inicjuj()
{
    this->punkty = 0;
    this->pytania = 0;
    this->procent = 0;
    this->procentz = 0;
}

/*Funkcja wyswietla statystyke*/
void Statystyka::Wyswietl()
{

    cout << "Liczba uzyskanych punktów: " << this->punkty << endl;
    cout << "Liczba pytań " << this->pytania << endl;
    cout << "Liczba punktów w procentach: " << this->procent<< "%"<< endl;
    cout << "Liczba blednych odp w procentach: " << this->procentz<< "%"<< endl;
}

/*Funkcja oblicza procentowy wynik*/
void Statystyka::Oblicz()
{
    this->procent = this->punkty*100.0 / this->pytania ;
}

/*Funkcja oblicza ilosc pytan*/
void Statystyka::Zlicz_pyt (){
    this->pytania++;
}

/*Funkcja oblicza ilosc zdobytych punktow*/
void Statystyka::Zlicz_pkt (){
    this->punkty++;
}
/*Funkcja oblicza procentowy wynik dla zlych odpowiedzi*/
void Statystyka::Oblicz_zle()
{
    this->procentz = (this->pytania-this->punkty)*100.0 / this->pytania;
}

using namespace std;
