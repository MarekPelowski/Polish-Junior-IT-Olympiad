Podzielność przez 9
Kod zadania: pod
XVII OIJ, zawody I stopnia Limit czasu: 1 s
26 września 2022 – 5 stycznia 2023 Limit pamięci: 256 MB
Uwaga: to zadanie jest zadaniem otwartym. Możesz sprawdzić wynik swojego zgłoszenia w systemie SIO2.
Bajtosia bardzo lubi liczby podzielne przez 9. Byłaby najszczęśliwsza, gdyby każda liczba była podzielna przez 9, ale świat
nie jest idealny. Na szczęście Bajtosia zauważyła, że dla dowolnej liczby naturalnej wystarczy zawsze zmienić co najwyżej
jedną cyfrę na inną, aby uzyskana liczba była podzielna przez 9. Niestety, Bajtosia nie zawsze potrafi ustalić, którą cyfrę
należy zmienić i na jaką. Czy pomożesz jej w tym zadaniu?
Wejście
W pierwszym (jedynym) wierszu wejścia znajduje się jedna liczba naturalna 𝑁 (1 ≤ 𝑁 ≤ 1018).
Wyjście
W pierwszym (jedynym) wierszu wyjścia powinna się znaleźć jedna dodatnia liczba całkowita 𝑀, podzielna przez 9,
o takiej samej liczbie cyfr co liczba 𝑁, różniąca się na co najwyżej jednej pozycji od liczby 𝑁.
Jeśli istnieje wiele rozwiązań, Twój program może wypisać dowolne z nich. Pamiętaj, że:
• Liczby nie mogą mieć zer wiodących (np. 09 to nie jest poprawny zapis liczby);
• W języku C++ do zapisu liczby 𝑁 nie wystarczy typ int, ponieważ jest ona zbyt duża. Użyj typu long long.
Ocenianie
Możesz rozwiązać zadanie w kilku prostszych wariantach – niektóre grupy testów spełniają pewne dodatkowe ograniczenia.
Poniższa tabela pokazuje, ile punktów otrzyma Twój program, jeśli przejdzie testy z takim ograniczeniem.
Dodatkowe ograniczenia Liczba punktów
𝑁 będzie potęgą liczby 10 18
𝑁 ≤ 1000 35
𝑁 ≤ 100 000 000 51
Przykłady
Wejście dla testu pod0a:
258
Wyjście dla testu pod0a:
288
Wejście dla testu pod0b:
45
Wyjście dla testu pod0b:
45
Wejście dla testu pod0c:
77
Wyjście dla testu pod0c:
72
