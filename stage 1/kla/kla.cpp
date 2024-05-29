#include <iostream>
#include <vector>
#include <algorithm>

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
    if(M > 0) {
        for(int i = 0; i < M; i++) {
            std::cin >> A[i];
        }
    }

    std::cin >> T;

    std::sort(H.begin(), H.end());
    std::sort(A.begin(), A.end(), std::greater<int>());

    int i = 0, ppl = 0;

    for(int growth : H) {
        if(i < M) {
            if(growth + A[i] >= T) {
                ppl++;
                i++;
            }
        } else {
            if(growth >= T) {
                ppl++;
            }
        }
    }

    std::cout << ppl;

    return 0;
}