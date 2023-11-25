Zadanie: Palindromy

Dana jest liczba naturalna 
�
N (
1
≤
�
≤
1
0
5
1≤N≤10 
5
 ). Zdefiniujmy palindrom jako liczbę, która czyta się tak samo od lewej do prawej i od prawej do lewej.

Twoim zadaniem jest sprawdzić, czy liczba 
�
N jest palindromem.

Wejście
W jedynym wierszu znajduje się jedna liczba naturalna 
�
N (
1
≤
�
≤
1
0
5
1≤N≤10 
5
 ).

Wyjście
Jeśli liczba 
�
N jest palindromem, wypisz "TAK". W przeciwnym razie wypisz "NIE".

Przykład
Wejście
Copy code
121
Wyjście
Copy code
TAK
Wejście
Copy code
12321
Wyjście
Copy code
TAK
Wejście
yaml
Copy code
9876
Wyjście
Copy code
NIE
Uwaga
W przykładzie pierwszym liczba 121 czyta się tak samo od lewej do prawej i od prawej do lewej, więc jest palindromem. W przykładzie drugim liczba 12321 również jest palindromem. Natomiast w przykładzie trzecim liczba 9876 nie jest palindromem.

To zadanie wymaga porównania cyfr liczby ze sobą w sposób symetryczny. Uczestnicy będą musieli użyć pętli do porównywania odpowiednich cyfr od początku i końca liczby.