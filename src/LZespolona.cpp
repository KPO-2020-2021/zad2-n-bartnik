#include <math.h>
#include<string>
#include <iostream>
#include <iomanip>
#include "LZespolona.hh"

using namespace std;
/*Funkcja wczytująca liczbę zespolną  w formule (a+bi)*/
void Wczytaj (LZespolona &Skl1)
{
  char nawias_l, nawias_p, i;
  cin >> nawias_l >> Skl1.re >> Skl1.im >> i >> nawias_p;
}
/*Funkcja wyswietlajaca liczbę zespolną  w formule (a+bi)*/
void Wyswietl(LZespolona Skl1)
{
  cout << "(" << Skl1.re << showpos << Skl1.im << noshowpos << "i)";
}

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

  Wynik.re = Skl1.re / Skl2; 
  Wynik.im = Skl1.im / Skl2;
  return Wynik;
}
/*Prototyp wczytywania przez strumień dla liczby zespolonej*/
LZespolona istream &operator >> (istream& Skl1);{
  char nawias_l, nawias_p, i;
  cin >> nawias_l >> Skl1.re >> Skl1.im >> i >> nawias_p;
}

