#include <iostream>
#include <cmath>

int countDigits(int n);

int main()
{
    int n;
    std::cin >> n;

    int maxNum = pow(10, countDigits(n) - 1);

    std::cout << n / maxNum << "   " << n % 10 << std::endl;

    for(int i = 10; i != maxNum; i*=10){
        if((n / maxNum) != n % i){
            std::cout << "NO";
            std::cout << "\n" << i << "\n";
        }

        maxNum /= 10;
    }

    return 0;
}

int countDigits(int n){
    int count = 0;

    while(n > 0){
        count++;
        n /= 10;
    }

    return count;
}