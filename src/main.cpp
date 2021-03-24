#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"

using namespace std;

int main(int argc, char **argv)
{

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
  LZespolona zespolona, zesp1;
  Statystyka statystyka;
  Inicjuj(statystyka);

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    cout << " Podaj wynik wyrazenia:  ";
    cout << WyrZ_PytanieTestowe << " "; /*Sprawdzenie wyświetlania pytania*/
    cin >> zespolona;                   /*Sprawdzenie wczytywania liczby zespolonej*/
    /*Operacje, ktore dzieja sie w przypadku gdy uzytkownik wpisze nieprawidlowe znaki*/
    if (cin.fail())
    {
      cout << "Blad zapisu liczby zespolonej!" << endl;
      cin.clear();             /* 'naprawia' failstate i strumien dziala poprawnie*/
      cin.ignore(99999, '\n'); /*ignoruje 99999 znakow lub do konca linii*/
      Zlicz_pyt(statystyka); /*Liczy pytanie*/
    }
    else
    {
      zesp1 = Oblicz(WyrZ_PytanieTestowe);
      cout << "Poprawny wynik to: " << zesp1 << endl;
    }
    if (zespolona == zesp1)
    {
      cout << "Poprawna odpowiedz" << endl;
      Zlicz_pyt(statystyka);  /*Liczy pytanie*/
      Zlicz_pkt(statystyka);  /*Liczy punkt*/
    }
    else
    {
      Zlicz_pyt(statystyka);  /*Liczy pytanie*/
      cout << "Zla odpowiedz";
    }
  }
  cout << endl;
/*Wyswietlanie koncowej statystyki*/
  Oblicz(statystyka);
  Oblicz_zle(statystyka);
  Wyswietl(statystyka);
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
