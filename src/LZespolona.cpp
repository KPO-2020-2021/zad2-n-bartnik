#include <math.h>
#include <string>
#include <iostream>
#include <iomanip>
#include "LZespolona.hh"
#include "Statystyki.hh"
#define MIN 0.001 /*Minimalna wartosc roznicy dla operatora porownania*/
using namespace std;

/*Sprzezenie liczby zespolonej*/
LZespolona Sprzezenie(LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik.re = Skl2.re;
  Wynik.im = -Skl2.im;
  return Wynik;
}
/*Modul podniesiony do kwardatu z liczby zespolonej (wg wzoru |a+bi|^2=a^2+b^2)*/
double Modul2(LZespolona Skl2)
{
  double Wynik;
  Wynik = Skl2.re * Skl2.re + Skl2.im * Skl2.im;
  return Wynik;
}

LZespolona operator+(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}
/*Odejmowanie liczb zespolonych analogicznie co dodawanie (zamiana znaku + na -)*/
LZespolona operator-(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}
/*Mnożenie liczb zespolonych na zasadzie wzoru (a+bi)(c+di)=ac+adi+cbi+db(-1)*/
LZespolona operator*(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl2.re * Skl1.im;
  return Wynik;
}
/*Dzielenie przy użyciu wzoru podanego w opisie zadania*/
LZespolona operator/(LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik = (Skl1 * Sprzezenie(Skl2)) / Modul2(Skl2);
  return Wynik;
}
/*Dzielenie przez skalar*/
LZespolona operator/(LZespolona Skl1, double Skl2)
{
  LZespolona Wynik;
  if (Skl2 == 0)
  {
    throw runtime_error("Dzielenie przez 0\n");
  }
  Wynik.re = Skl1.re / Skl2;
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}
/*Wczytywanie przez strumień dla liczby zespolonej. Funkcja ustawia status "failbit" w momencie, kiedy uzytkownik wpisze niepozadany w danym momencie znak.*/
istream &operator>>(istream &StrWej, LZespolona &Skl1)
{
  char nawias_l, nawias_p, i;

  StrWej >> nawias_l;
  if (nawias_l != '(')
  {
    StrWej.setstate(ios::failbit);
  }

  StrWej >> Skl1.re >> Skl1.im >> i;
  if (i != 'i')
  {
    StrWej.setstate(ios::failbit);
  }
  StrWej >> nawias_p;
  if (nawias_p != ')')
  {
    StrWej.setstate(ios::failbit);
  }
  return StrWej;
}
/*Wyczytywanie przez strumień dla liczby zespolonej.*/
ostream &operator<<(ostream &StrWyj, LZespolona Skl1)
{
  char nawias_l, nawias_p, i;
  StrWyj << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";
  return StrWyj;
}
/*Operator porownania. Jezeli wartosc bezwzgledna roznicy dwoch liczb dla ich czesci rzeczywistych i urojonych jest wieksza od wartosci MIN,
to funkcja zwraca wartosc false. */
bool operator==(const LZespolona Skl1, const LZespolona Skl2)
{

  if (abs(Skl2.re - Skl1.re) <= MIN && abs(Skl2.im - Skl1.im) <= MIN)
    return true;

  return false;
}
