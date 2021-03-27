#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

/*Struktura dla statystyki*/
struct Statystyka
{
    int punkty; /*Punkty za poprawne odpowiedzi*/
    int pytania; /*Ilosc pytan*/
    double procent; /*Procent poprawnych odpowiedzi*/
    double procentz; /*Procnt złych odpowiedzi*/

/*Nagłówki wszystkich funkcji występujących w pliku Statystyki.cpp*/
void Inicjuj();
void Wyswietl();
void Oblicz();
void Zlicz_pyt();
void Zlicz_pkt();
void Oblicz_zle();
};
#endif
