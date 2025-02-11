#include <iostream>
#include <cmath>

int countDigits(int n);

int main()
{
    int n;
    std::cin >> n;
    bool isPalindrome = true;

    int maxNum = pow(10, countDigits(n) - 1);

    for(int i = 1; i != maxNum && i <= maxNum / 10; i*=10){
        if((n / maxNum) % 10 != (n % (i * 10)) / i){
            isPalindrome = false;
            break;
        }
        maxNum /= 10;
    }

    if(isPalindrome == 1){
        std::cout << "YES" << std::endl;
    }
    else{
        std::cout << "NO" << std::endl;
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