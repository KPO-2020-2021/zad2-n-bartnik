#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

using namespace std;

int main(int argc, char **argv)
{
  LZespolona zesp1, zesp2;
  zesp1.re = 1;
  zesp1.im = 2;

  if (argc < 2)
  {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }

  BazaTestu BazaT = {nullptr, 0, 0};

  if (InicjalizujTest(&BazaT, argv[1]) == false)
  {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona zespolona;

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    cout << " Podaj wynik wyrazenia:  ";
    Wyswietl(WyrZ_PytanieTestowe); /*Sprawdzenie wyświetlania pytania*/
    Wczytaj(zespolona);/*Sprawdzenie wczytywania liczby zespolonej*/
    cout<<endl;
  }

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
