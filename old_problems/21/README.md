Przesuwanie króla
Kod zadania: kro
XVII OIJ, zawody I stopnia Limit czasu: 1 s
26 września 2022 – 5 stycznia 2023 Limit pamięci: 64 MB
Bajtek przygotowuje się do turnieju szachowego. Obecnie skupia się na grze w fazie końcowej, gdy na szachownicy
pozostaje już niewiele figur i może skupić się na ruchach jednej z nich.
W tym momencie Bajtek jest skoncentrowany na królu – figurze szachowej, którą w każdym ruchu może przesunąć
o jedno pole w wybranym z ośmiu kierunków:
• do góry (N),
• w prawo (E),
• w dół (S),
• w lewo (W),
• do góry i w prawo (NE),
• w dół i w prawo (SE),
• w dół i w lewo (SW),
• do góry i w lewo (NW).
N
E
NE
SW S
W
SE
NW
K
K
a b c d e f g h
1
2
3
4
5
6
7
8
Bajtek chce jak najszybciej przemieścić króla z jego obecnej pozycji na inne wybrane pole, zanim przeciwnik zdąży
wykorzystać korzystną dla siebie sytuację. Pomóż mu w tym zadaniu i napisz program, który znajdzie możliwy ciąg ruchów
króla.
Wejście
W pierwszym wierszu wejścia znajdują się dwa znaki opisujące bieżącą pozycję króla na szachownicy o wymiarach 8×8.
Pierwszy znak opisuje kolumnę, w której znajduje się król i jest jedną z małych liter a, b, c, d, e, f, g, h. Drugi znak
opisuje rząd, w którym znajduje się król i jest jedną z cyfr 1, 2, 3, 4, 5, 6, 7, 8.
W drugim wierszu wejścia znajdują się dwa znaki (w formacie takim jak z pierwszego wiersza) opisujące docelową
pozycję króla.
Możesz przyjąć, że pozycja początkowa króla różni się od pozycji docelowej.
Wyjście
W pierwszym wierszu wyjścia powinna się znaleźć liczba naturalna, opisująca najmniejszą liczbę ruchów potrzebnych
do przemieszczenia króla z pozycji początkowej do pozycji docelowej.
W drugim (ostatnim) wierszu wyjścia powinien się znaleźć ciąg kolejnych ruchów jakie należy wykonać. Opis każdego
ruchu to jedna lub dwie wielkie litery zgodnie z listą ruchów powyżej (N, E, S, W, NE, SE, SW, NW). Ruchy należy wypisać
oddzielając je pojedynczymi odstępami.
Jeśli istnieje wiele możliwych rozwiązań, Twój program może wypisać dowolne z nich.
