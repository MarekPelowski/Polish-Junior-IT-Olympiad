Zadanie: Liczby doskonałe

Liczba doskonała to taka liczba naturalna, która jest sumą swoich dzielników właściwych (tj. wszystkich, z wyjątkiem samej siebie). Na przykład, liczba 28 jest doskonała, ponieważ 
1
+
2
+
4
+
7
+
14
=
28
1+2+4+7+14=28.

Napisz program, który znajduje i wypisuje wszystkie liczby doskonałe w danym przedziale 
[
�
,
�
]
[a,b] (
1
≤
�
≤
�
≤
1
0
6
1≤a≤b≤10 
6
 ).

Wejście
W jedynym wierszu znajdują się dwie liczby całkowite oddzielone spacją: 
�
a i 
�
b (
1
≤
�
≤
�
≤
1
0
6
1≤a≤b≤10 
6
 ).

Wyjście
Wypisz wszystkie liczby doskonałe w przedziale 
[
�
,
�
]
[a,b], każdą w nowej linii. Jeśli w danym przedziale nie ma żadnych liczb doskonałych, wypisz "BRAK".

Przykład
Wejście
Copy code
20 50
Wyjście
Copy code
28
Uwaga
W przedziale 
[
20
,
50
]
[20,50] jedyną liczbą doskonałą jest 28, ponieważ 
1
+
2
+
4
+
7
+
14
=
28
1+2+4+7+14=28.

To zadanie wymaga sprawdzenia każdej liczby w danym przedziale pod kątem doskonałości. Uczestnicy będą musieli zaimplementować algorytm znajdowania dzielników danej liczby i sumowania ich.