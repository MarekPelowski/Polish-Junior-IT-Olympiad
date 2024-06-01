#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    long long T;
    std::cin >> N >> T;
    std::vector<long long> A(100);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    std::reverse(A.begin(), A.end());
    long long num = 1;
    std::vector<long long> divisors;
    std::vector<long long> smallnums;

    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << "\n\n";

    for(int i = 0; i < N; i++) {
        if(T % A[i] == 0) {
            divisors.push_back(A[i]);
        }
    }

    for(int i = 0; i < divisors.size(); i++) {
        std::cout << divisors[i] << " ";
    }

    return 0;
}

//not finished yet :)