#include <iostream>
#include <vector>

int main()
{
    int N, M, T;
    std::cin >> N;

    std::vector<int> H(N);
    for(int i = 0; i < N; i++) {
       std::cin >> H[i];
    }

    std::cin >> M;
    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::cin >> T;

    return 0;
}

// (N) liczba osób
// ciąg (H) wzrostów osób
// (M) liczba par klapek w sklepie
// ciąg (A) rozmiarów klapek
// (T) minimalny wzrost do zjazdu