
Oto implementacja w C++ dla zadania "Szereg Fibonacciego":

cpp
Copy code
#include <iostream>

// Funkcja zwracająca N-ty element szeregu Fibonacciego
int fibonacci(int N) {
    if (N <= 1) {
        return N;
    } else {
        int a = 0, b = 1, temp;
        for (int i = 2; i <= N; ++i) {
            temp = a + b;
            a = b;
            b = temp;
        }
        return b;
    }
}

int main() {
    // Wczytaj liczbę naturalną N
    int N;
    std::cin >> N;

    // Wypisz N-ty element szeregu Fibonacciego
    std::cout << fibonacci(N) << std::endl;

    return 0;
}
W tym programie funkcja fibonacci przyjmuje liczbę naturalną 
�
N i zwraca 
�
N-ty element szeregu Fibonacciego. Wewnątrz funkcji stosowana jest pętla, aby obliczyć kolejne elementy szeregu. Program wczytuje 
�
N i wypisuje odpowiedni element na standardowe wyjście.