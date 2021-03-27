#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include<iostream>
using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */



/* Przeciązenia operatorów operacji arytmetycznych oraz dodatkowe funkcje*/


LZespolona  operator + (LZespolona  Skl2);
LZespolona  operator - ( LZespolona  Skl2);
LZespolona  operator * ( LZespolona  Skl2);
LZespolona  operator / ( LZespolona  Skl2);
LZespolona  operator / (double  Skl2);
LZespolona Sprzezenie();
bool operator==(LZespolona Skl2);/*Naglowek funkcji porównującej liczby*/
double Modul2();
};
istream& operator >> (istream &StrWej, LZespolona &Skl1); /*Naglowek funkcji wczytującej wyrazenie*/
ostream& operator << (ostream &StrWyj, LZespolona Skl1); /*Naglowek funkcji wyczytującej wyrazenie*/



#endif
