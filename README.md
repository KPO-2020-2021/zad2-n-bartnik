# Projekt 2 - Arytmetyka liczb zespolonych

## Cel ćwiczenia
Wykształcenie umiejętności definiowania przeciążeń operatorów arytmetycznych dwuargumentowych i jednoargumentowych dla własnych struktur danych oraz operatora porównania. Przećwiczenie podstawowych operacji na strumieniach plikowych.  Nabycie umiejętności definiowania przeciążeń operacji na strumieniach.

## Opis zadania programowego
Należy napisać program, który umożliwia wykonanie prostego sprawdzianu z arytmetyki liczb zespolonych.  Sprawdzian ma dotyczyć operacji dodawania, odejmowania, mnożenia i dzielenia. Zakłada się, ̇ze są dostępne co najmniej dwa zestawy pytań. Dla uproszczenia zakładamy, ̇ze liczby zespolone będą wyświetlane w nawiasach. W tej formie będą również wprowadzane. Przykładowy zapis wyrażeń podany jest poniżej.

	(4.2+2i)+(0+2i)
	(3-0i)*(-1+2.1i)
	(0-4i)/(3-1i)

W zapisie tym dla ułatwienia zachowanych jest kilka reguł:
* każda liczba zespolona zawsze zapisywana jest w nawiasach półokrągłych,
* zawsze występuje liczba oznaczająca część rzeczywistą, niezależnie od tego czy jest ona różna od zera, czy też równa jest zeru,
* zawsze  występuje  liczba  oznaczająca  część urojoną, niezależnie od tego czy jest ona różna od zera, czy też równa jest zeru,
* zestaw pytań zakończony jest znakiem kropki.

W trakcie realizacji testu program wyświetla kolejne wyrażenie i pyta użytkownika o wyniko peracji.  Udzieloną odpowiedź sprawdza z poprawnym wynikiem.  W przypadku poprawnej odpowiedzi, potwierdza ten fakt, zaś w przypadku błędnej odpowiedzi stwierdza ten fakt i podaje odpowiedź właściwą.  Po zakończeniu testu podawana jest statystyka błędnych i poprawnych odpowiedzi.


## Struktura repozytorium
Repozytorium z zalążkiem do zadania ma następującą strukturę:

&nbsp;&nbsp; [src](src/) - folder z plikami źródłowymi\
&nbsp;&nbsp; [inc](inc/)-- folder z plikami nagłówkowymi\
&nbsp;&nbsp; [tests](tests/) - zawiera pliki źródłowe testów oraz biblioteki doctest\
&nbsp;&nbsp; ├── bin - pliki binarne testów\
&nbsp;&nbsp; └── doctest - pliki źródłowe dla biblioteki odpowiedzialnej za testy\
&nbsp;&nbsp; [man](man/) - instrukcje do zadania oraz inne pomoce naukowe\
&nbsp;&nbsp; Makefile - plik z dyrektywami do automatycznej kompilacji\
&nbsp;&nbsp; .gitignore  - plik określający, które pliki mają być ignorowane przez Gita\

## Odnośniki do źródeł
[Strona kursu z Programowania Obiektowego](https://kcir.pwr.edu.pl/~kreczmer/po/)


###############################################################
Kompilowanie i uruchamianie (opcja run zmieniona na opcje latwy lub trudny):
make clean
make 
make latwy/trudny
###############################################################
Wczytywanie z pliku:
Stworzone dwa pliki tekstowe: spr1, spr2. Plik spr1 jest przypisany dla wyświetlania testu łatwego, plik spr2 jest przypisany dla wyświetlania dla testu trudnego. 
Testy są jedynie przykładowe i nie mają odzwierciedlenia w rzeczywistym poziomie trudności.
W strukturze BazaTestu utworzona jest specjalna zmienna typu fstream dla pliku. 
W kodzie dla bazy testu  wskaźnik bazy (wskBazaTestu) wskazuje na plik i go otwiera. Następnie następuje sprawdzanie czy, czy plik został otworzony poprawnie. 
Na końcu wczytywane jest każde kolejne pytanie aż do końca  i w przypadku niewłaściwego zapisu wyświetlany jest odpowiedni 
##############################################################
Problemy:
*Największy problem pojawił się przy porównywaniu liczb do odpowiednich miejsc po przecinku w testach.
Testy działają, ale tylko dla wprowadzonych w tym momencie wartości. Dla większej ilości liczb po przecinku testy pokazują błąd. 
*Program wyświetla ostrzeżenia o nieużywanych zmiennych, pomimo tego, że są one używane do porówny2wania (plik LZespolona.cpp).
