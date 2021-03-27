#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyki.hh"

TEST_CASE("test LZespolona Suma")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 2;
    z.im = -2;

    CHECK(x + y == z);
}

TEST_CASE("test LZespolona Suma")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x + y == z);
}

TEST_CASE("test LZespolona Suma")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1;
    z.im = 1;

    CHECK(x + y == z);
}

TEST_CASE("test LZespolona Suma")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 1;
    z.im = 1;

    CHECK(x + y == z);
}

TEST_CASE("test LZespolona Suma")
{
    LZespolona x, y, z;

    x.re = 1.000009;
    x.im = 1;

    y.re = 0.000001;
    y.im = 0.000001;

    z.re = 1;
    z.im = 1;

    CHECK(x + y == z);
}

/*#############################################################*/
/*ROZNICA*/

TEST_CASE("test LZespolona Roznica")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = -3;

    z.re = 0;
    z.im = 4;

    CHECK(x - y == z);
}

TEST_CASE("test LZespolona Roznica")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x - y == z);
}

TEST_CASE("test LZespolona Roznica")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.0;
    y.im = 0.0;

    z.re = 1;
    z.im = 1;

    CHECK(x - y == z);
}

TEST_CASE("test LZespolona Roznica")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0.00001;
    y.im = 0.00001;

    z.re = 0.99999;
    z.im = 0.99999;

    CHECK(x - y == z);
}

TEST_CASE("test LZespolona Roznica")
{
    LZespolona x, y, z;

    x.re = 1.6;
    x.im = 1.6;

    y.re = 0.01;
    y.im = 0.01;

    z.re = 1.59;
    z.im = 1.59;

    CHECK(x - y == z);
}

/*######################################################*/
/*MNOZENIE*/

TEST_CASE("test LZespolona Mnozenie")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 0;

    z.re = 0;
    z.im = 0;

    CHECK(x * y == z);
}

TEST_CASE("test LZespolona Mnozenie")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 0;

    z.re = 1;
    z.im = 1;

    CHECK(x * y == z);
}

TEST_CASE("test LZespolona Mnozenie")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 0;
    y.im = 1;

    z.re = -1;
    z.im = 1;

    CHECK(x * y == z);
}

TEST_CASE("test LZespolona Mnozenie")
{
    LZespolona x, y, z;

    x.re = 1;
    x.im = 1;

    y.re = 1;
    y.im = 1;

    z.re = 0;
    z.im = 2;

    CHECK(x * y == z);
}

/*INNE*/
TEST_CASE("test LZespolona Sprzezenie im!=0")
{
    LZespolona y, z;

    y.re = 1;
    y.im = 1;

    z.re = 1;
    z.im = -1;

    CHECK(y.Sprzezenie() == z);
}

TEST_CASE("test LZespolona Sprzezenie im==0")
{
    LZespolona y, z;

    y.re = 1;
    y.im = 0;

    z.re = 1;
    z.im = 0;

    CHECK(y.Sprzezenie() == z);
}

TEST_CASE("test LZespolona Modul2")
{
    LZespolona y;
    double z = 2;

    y.re = 1;
    y.im = 1;

    CHECK(y.Modul2() == z);
}

/*TESTY OPERATOROW*/
TEST_CASE("test LZespolona Suma")
{
    WyrazenieZesp a = {{1, 1}, Op_Dodaj, {1, 1}};
    LZespolona z;

    z.re = 2;
    z.im = 2;

    CHECK(a.Oblicz() == z);
}

TEST_CASE("test LZespolona Roznica")
{
    WyrazenieZesp a = {{1, 1}, Op_Odejmij, {1, 1}};
    LZespolona z;

    z.re = 0;
    z.im = 0;

    CHECK(a.Oblicz() == z);
}

TEST_CASE("test LZespolona Mnozenie")
{
    WyrazenieZesp a = {{1, 1}, Op_Mnoz, {1, 1}};
    LZespolona z;

    z.re = 0;
    z.im = 2;

    CHECK(a.Oblicz() == z);
}

TEST_CASE("test LZespolona Dzielenie")
{
    WyrazenieZesp a = {{1, 1}, Op_Dziel, {1, 1}};
    LZespolona z;

    z.re = 1;
    z.im = 0;

    CHECK(a.Oblicz() == z);
}
/*Statystyka*/
TEST_CASE("test LZespolona Dzielenie")
{
    Statystyka a = {5, 10, 0, 0};
    a.Oblicz_zle();
    a.Oblicz();
    CHECK(a.procent == 50);
    CHECK(a.procentz == 50);
}

/*Wyswietlanie */

TEST_CASE("Wyswietlanie zaokraglone")
{
    LZespolona a;
    a.re = 1.0 / 3.0;
    a.im = 1.0 / 3.0;
    std::ostringstream out;
    out << a;

    CHECK("(0.333333+0.333333i)" == out.str());
}

/*Wczytywanie*/
TEST_CASE("Wczytywanie")
{
    LZespolona a;

    std::istringstream in("(10+10.1i)");
    in >> a;
    std::ostringstream out;
    out << a;

    CHECK("(10+10.1i)" == out.str());
}