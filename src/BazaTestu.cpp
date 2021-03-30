#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

/*
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *   
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
void UstawTest(BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan)
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}

/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych 
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *       
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
bool InicjalizujTest(BazaTestu *wskBazaTestu, const char *sNazwaTestu)
{
  if (!strcmp(sNazwaTestu, "latwy"))
  { /*otwieranei wyrażeń z pliku dla polecenia latwy*/

    wskBazaTestu->plik.open("spr1", ios::in);
    if (!wskBazaTestu->plik.good()) /*sprawdzanie, czy plik został poprawnie otworzony*/
    {
      cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
      return false;
    }
    return true;
  }
  /*analogicznie dla testu trudnego*/
  if (!strcmp(sNazwaTestu, "trudny"))
  {

    wskBazaTestu->plik.open("spr2", ios::in);
    if (!wskBazaTestu->plik.good())
    {
      cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
      return false;
    }
    return true;
  }

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}

/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
bool PobierzNastpnePytanie(BazaTestu *wskBazaTestu, WyrazenieZesp *wskWyrazenie)
{
  while (!wskBazaTestu->plik.eof()) /*sprawdzanie końca pliku*/
  {
    wskBazaTestu->plik >> *wskWyrazenie; /*Sprawdzenie wczytywania wyrazenia zespolonego z pliku*/

    if (wskBazaTestu->plik.fail())
    {
      cout << "Blad zapisu liczby wyrazenia!" << endl; /*wyswietlanie komunikatu, gdy wyrazenie nie ma poprawnej formy*/
      wskBazaTestu->plik.clear();                      /* 'naprawia' failstate i strumien dziala poprawnie*/
      wskBazaTestu->plik.ignore(99999, '\n');          /*ignoruje 99999 znakow lub do konca linii*/
    }
    else
    {
      break;
    }
  }
  if (wskBazaTestu->plik.eof()) /*sprawdzanie końca pliku*/
    return false;

  return true;
}
