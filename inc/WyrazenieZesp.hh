#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH



#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego



/* Nagłówki funkcji dla wyrażenia zespolonego*/

LZespolona Oblicz();
};
istream &operator>>(istream &StrWe, WyrazenieZesp &WyrZ);
ostream &operator<<(ostream &StrWyj, const WyrazenieZesp &WyrZ);


#endif
