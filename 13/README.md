Zadanie: "Szyfr Cezara"

Szymon uwielbia rozwiązywać zagadki i ostatnio odkrył fascynujący świat szyfrów. Postanowił użyć prostego szyfru Cezara do zakodowania tajnej wiadomości. Szymon używał standardowego szyfru Cezara, przesuwając litery o stałą liczbę miejsc w alfabecie. Jednakże, nie zawsze używał dodatniej liczby jako przesunięcia.

Twoim zadaniem jest napisać program, który odkoduje wiadomość zakodowaną przez Szymona. Zakodowana wiadomość składa się z małych liter alfabetu angielskiego (a-z), a przesunięcie znane jest jako klucz.

Napisz program, który wczytuje zakodowaną wiadomość i klucz, a następnie odkodowuje wiadomość.

Wejście:

Pierwsza linia zawiera zakodowaną wiadomość składającą się z małych liter (długość wiadomości nie przekroczy 100).
Druga linia zawiera liczbę całkowitą 
�
K (-25 <= 
�
K <= 25) - klucz przesunięcia.
Wyjście:

Wydrukuj zdekodowaną wiadomość.
Przykład:

vbnet
Copy code
Wejście:
yf'nx tsj ymfy htwj ymnx fhyj
5

Wyjście:
to jest taka prosta wiadomosc
Wyjaśnienie:
Dla każdej litery w wiadomości, przesunięto ją o 5 miejsc w lewo w alfabecie, uzyskując zdekodowaną wiadomość.