Lizak
Kod zadania: liz
XVI OIJ, zawody II stopnia Limit czasu: 4 s (C++) / 12 s (Python)
12 marca 2022 Limit pamięci: 256 MB
Bajtek udał się do cukierni. Jego uwagę przykuł długi lizak składający się z N części równej długości. Każda część
lizaka ma pewien określony smak.
Bajtek chciałby wybrać pewien spójny fragment tego lizaka. Aby to zrobić, może on odłamać pewną liczbę części (być
może zero) z lewej i prawej strony tego lizaka. Poniższy rysunek pokazuje kilka możliwości wybrania fragmentów z lizaka
przedstawionego powyżej. Przykładowe fragmenty oznaczone są czarną ramką.
Bajtek uważa fragment lizaka za smaczny, jeżeli zawiera co najmniej trzy części o tym samym smaku. Zwróć uwagę,
że Bajtka nie interesuje jaki dokładnie smak będzie występował trzy razy, ani ile będzie różnych smaków w tym fragmencie.
Zauważ, że wszystkie fragmenty z rysunku powyżej są smaczne.
Bajtek nie zamierza się przejadać. Chciałby więc wybrać najkrótszy smaczny fragment lizaka, czyli taki fragment który
składa się z jak najmniejszej liczby części. Pomóż mu!
Napisz program, który na podstawie opisu lizaka wyznaczy długość jego najkrótszego smacznego fragmentu lub stwierdzi
że nie jest możliwe wybranie żadnego smacznego fragmentu.
Wejście
W pierwszym wierszu wejścia znajduje się jedna liczba naturalna N (1 ≤ N ≤ 500 000) określająca liczbę części dostępnego lizaka w sklepie. W drugim (ostatnim) wierszu wejścia znajduje się opis części tego lizaka. Lizak ten reprezentowany
jest jako ciąg N liczb naturalnych Ai (1 ≤ Ai ≤ 109
). Są to oznaczenia smaków fragmentów lizaka w kolejności ich
występowania w lizaku od lewej do prawej. Różne smaki reprezentowane są różnymi liczbami.
Wyjście
W pierwszym (jedynym) wierszu wyjścia powinna się znaleźć jedna liczba całkowita – minimalna liczba części, które ma
smaczny fragment lizaka zgodnie z warunkami powyżej. Jeśli z lizaka opisanego na wejściu nie można wybrać smacznego
fragmentu to zamiast tego należy wypisać tylko jedno słowo NIE.
Ocenianie
Możesz rozwiązać zadanie w kilku prostszych wariantach – niektóre grupy testów spełniają pewne dodatkowe ograniczenia.
Poniższa tabela pokazuje, ile punktów otrzyma Twój program, jeśli przejdzie testy z takim ograniczeniem.
Lizak

c Olimpiada Informatyczna Juniorów, 2022
oij.edu.pl
Olimpiada finansowana jest ze środków Ministerstwa Edukacji i Nauki
w ramach zadania publicznego „Organizacja i przeprowadzenie olimpiad
i turniejów w latach szkolnych 2019/2020, 2020/2021, 2021/2022”.
1/2
Dodatkowe ograniczenia Liczba punktów
Ai ≤ 2 9
każdy smak występuje co najwyżej 3 razy, Ai ≤ 500 11
N ≤ 100 25
N ≤ 1 500 45
Ai ≤ 500 000 80
Przykłady
Wejście dla testu liz0a:
10
6 8 4 8 6 8 8 2 6 6
Wyjście dla testu liz0a:
4
Wyjaśnienie do przykładu: Lizak ten zilustrowany jest na poprzedniej stronie. Najkrótszy fragment, który zawiera trzy
takie same smaki rozpoczyna się od części czwartej i kończy na części siódmej (składa się z czterech części). Oznaczenia
smaków kolejnych części tego fragmentu to: 8, 6, 8, 8. Smak oznaczony 8 powtarza się trzykrotnie.
Wejście dla testu liz0b:
5
1 2 3 4 5
Wyjście dla testu liz0b:
NIE
Wejście dla testu liz0c:
5
1 1 1 1 1
Wyjście dla testu liz0c:
3
Wejście dla testu liz0d:
7
9 99 999 9 999 99 9
Wyjście dla testu liz0d:
7
Pozostałe testy przykładowe
- test liz0e: N = 2 000, Ai = i dla i = 1, 2, . . . ,N
- test liz0f: N = 500 000, lizak składa się naprzemiennie z części 1, 2, 1, 2, ..., 1, 2
