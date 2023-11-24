#include <iostream>
#include <cmath>

int countDigits(int n);

int main()
{
    int n;
    std::cin >> n;

    int maxNum = pow(10, countDigits(n) - 1);
    // important line:  || maxNum <= pow(10, (countDigits(n) / 2) - 1)

    for(int i = 1; i != maxNum; i*=10){
        if((n / maxNum) % 10 != (n % (i * 10)) / i){
            std::cout << "NO #" << i << std::endl;
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