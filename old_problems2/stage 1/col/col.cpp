#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int M;
    long long N = 1;
    std::cin >> M;

    std::vector<long long> A;

    std::cout << 1 << " ";

    for(int i = 0; i < M - 1; i++){
        if(N % 3 == 1 && (N / 3) > 1 && (N / 3) % 3 != 0 && (N / 3) % 2 != 0)
            N = (N / 3);
        else
            N*=2;

        std::cout << N << " ";
    }


    return 0;
}

