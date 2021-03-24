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
};

/*Nagłówki wszystkich funkcji występujących w pliku Statystyki.cpp*/
void Inicjuj(Statystyka &stat);
void Wyswietl(Statystyka stat);
void Oblicz(Statystyka &stat);
void Zlicz_pyt(Statystyka &stat);
void Zlicz_pkt(Statystyka &stat);
void Oblicz_zle(Statystyka &stat);
#endif
