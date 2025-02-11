Zadanie: Klocki na Planszy
Rozważmy planszę o rozmiarze 
�
×
�
N×M składającą się z klocków o jednostkowej szerokości i wysokości. Każdy klocek jest przedstawiony jako znak '#' oznaczający pełny klocek lub '.' oznaczający pustą przestrzeń. Twoim zadaniem jest znalezienie największego prostokąta, który składa się wyłącznie z pełnych klocków.

Napisz program, który wczytuje planszę i znajduje pole największego prostokąta składającego się z pełnych klocków.

Wejście:

Pierwsza linia zawiera dwie liczby całkowite 
�
N i 
�
M (1 ≤ 
�
,
�
N,M ≤ 100) - wymiary planszy.
Następne 
�
N linii zawierają po 
�
M znaków ('#' lub '.') reprezentujących planszę.
Wyjście:

Jeden wiersz zawierający pole największego prostokąta składającego się z pełnych klocków.
Przykład:

makefile
Copy code
Wejście:
5 6
......
.####.
.##...
.###..
......

Wyjście:
6
Uwaga:
W przykładzie powyżej, największy prostokąt składający się z pełnych klocków ma pole 6 (2 klocki szerokości i 3 klocki wysokości).