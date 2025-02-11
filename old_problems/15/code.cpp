#include <iostream>

int main()
{
    int N;
    std::cin >> N;

    int sum = 0;

    while(N > 0){
        sum += N % 10;
        N /= 10;
    }

    std::cout << sum;

    return 0;
}