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
  statystyka.Inicjuj();

  while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe))
  {
    int m = 0;
    cout << " Podaj wynik wyrazenia:  ";
    cout << WyrZ_PytanieTestowe << "= ";   /*Sprawdzenie wyświetlania pytania*/
    zesp1 = WyrZ_PytanieTestowe.Oblicz(); /*oblicza wyrazenie*/
    /*Wczytywanie wyrazenia w petli w przypadku, gdy uzytkownik nie wpisze wyrazenia w poprawnej postaci*/
    while (m < 3)
    {
      cin >> zespolona; 
      cout<<endl;
      /*Operacje, ktore dzieja sie w przypadku gdy uzytkownik wpisze nieprawidlowe znaki*/
      if (cin.fail())
      {
        cout << "Blad zapisu liczby zespolonej!" << endl;
        cin.clear();             /* 'naprawia' failstate i strumien dziala poprawnie*/
        cin.ignore(99999, '\n'); /*ignoruje 99999 znakow lub do konca linii*/
        m++;                     /*licznik petli*/
      }
      else
      {
        break;
      }
    }

    if (zespolona == zesp1)
    {
      cout << "Poprawna odpowiedz" << endl;
      statystyka.Zlicz_pyt(); /*Liczy pytanie*/
      statystyka.Zlicz_pkt(); /*Liczy punkt*/
    }
    else
    {
      statystyka.Zlicz_pyt(); /*Liczy pytanie*/
      cout << "Zla odpowiedz"<<endl;
    }
  }
  cout << endl;
  /*Wyswietlanie koncowej statystyki*/
  statystyka.Oblicz();
  statystyka.Oblicz_zle();
  statystyka.Wyswietl();
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;
}
