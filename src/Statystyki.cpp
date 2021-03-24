#include "Statystyki.hh"
#include <iostream>

/*FUnkcja zeruje kazda zmienna w strukturze Statystyka. Jest to potrzebne do prawidłowego zliczania punktów*/
void Inicjuj(Statystyka &stat)
{
    stat.punkty = 0;
    stat.pytania = 0;
    stat.procent = 0;
    stat.procentz = 0;
}

/*Funkcja wyswietla statystyke*/
void Wyswietl(Statystyka stat)
{

    cout << "Liczba uzyskanych punktów: " << stat.punkty << endl;
    cout << "Liczba pytań " << stat.pytania << endl;
    cout << "Liczba punktów w procentach: " << stat.procent<< "%"<< endl;
    cout << "Liczba blednych odp w procentach: " << stat.procentz<< "%"<< endl;
}

/*Funkcja oblicza procentowy wynik*/
void Oblicz(Statystyka &stat)
{
    stat.procent = stat.punkty*100.0 / stat.pytania ;
}

/*Funkcja oblicza ilosc pytan*/
void Zlicz_pyt (Statystyka &stat){
    stat.pytania++;
}

/*Funkcja oblicza ilosc zdobytych punktow*/
void Zlicz_pkt (Statystyka &stat){
    stat.punkty++;
}
/*Funkcja oblicza procentowy wynik dla zlych odpowiedzi*/
void Oblicz_zle(Statystyka &stat)
{
    stat.procentz = (stat.pytania-stat.punkty)*100.0 / stat.pytania;
}

using namespace std;
