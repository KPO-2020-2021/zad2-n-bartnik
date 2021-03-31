#include <math.h>
#include <string>
#include <iostream>
#include <iomanip>
// #define M_PI 3.14159;
#include "LZespolona.hh"
#include "Statystyki.hh"

#define MIN 0.001 /*Minimalna wartosc roznicy dla operatora porownania*/
using namespace std;

/*Sprzezenie liczby zespolonej*/
LZespolona LZespolona::Sprzezenie()
{

  this->re = this->re;
  this->im = -this->im;
  return *this;
}
/*Modul podniesiony do kwardatu z liczby zespolonej (wg wzoru |a+bi|^2=a^2+b^2)*/
double LZespolona::Modul2()
{
  double Wynik;
  Wynik = this->re * this->re + this->im * this->im;
  return Wynik;
}

LZespolona LZespolona::operator+(LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}
/*Odejmowanie liczb zespolonych analogicznie co dodawanie (zamiana znaku + na -)*/
LZespolona LZespolona::operator-(LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = this->re - Skl2.re;
  Wynik.im = this->im - Skl2.im;
  return Wynik;
}
/*Mnożenie liczb zespolonych na zasadzie wzoru (a+bi)(c+di)=ac+adi+cbi+db(-1)*/
LZespolona LZespolona::operator*(LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = this->re * Skl2.re - this->im * Skl2.im;
  Wynik.im = this->re * Skl2.im + Skl2.re * this->im;
  return Wynik;
}
/*Dzielenie przy użyciu wzoru podanego w opisie zadania*/
LZespolona LZespolona::operator/(LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik = ((*this) * Skl2.Sprzezenie()) / Skl2.Modul2();
  return Wynik;
}
/*Dzielenie przez skalar*/
LZespolona LZespolona::operator/(double Skl2)
{
  LZespolona Wynik;
  if (Skl2 == 0)
  {
    throw runtime_error("Dzielenie przez 0\n");
  }
  Wynik.re = this->re / Skl2;
  Wynik.im = this->im / Skl2;
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
bool LZespolona::operator==(const LZespolona Skl2) const
{

  if (abs(Skl2.re - this->re) <= MIN && abs(Skl2.im - this->im) <= MIN)
    return true;

  return false;
}

LZespolona &operator+= (LZespolona &Arg1, LZespolona const &Arg2)
{
  Arg1 = Arg1 + Arg2;
  return Arg1;
}
LZespolona&operator/=(LZespolona &Arg1, LZespolona &Arg2)
{
  LZespolona Wynik;
  if (Arg2.re != 0 || Arg2.im != 0)
  {

    Wynik = (Arg1 / Arg2);
  }
  else
  {
    throw runtime_error("Dzielenie przez 0\n");
  } return Arg1;
}
double arg(LZespolona z)
{
  double wynik;
  if (z.re > 0)
  {
    wynik = atan2(z.im, z.re);
    cout << wynik;
  }
  else
  {
    wynik = atan2(z.im, z.re) + M_PI;
    cout << wynik;
  }
  return wynik;
}