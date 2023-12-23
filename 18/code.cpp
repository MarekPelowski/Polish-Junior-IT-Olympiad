#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    bool isPrime = true;

    int sum = 0;

    while(n > 0){
        sum += n % 10;
        n /= 10;
    }

    for(int i = 2; i * i < sum; i++){
        if(sum % i == 0){
            isPrime = false;
            break;
        }
    }

    std::cout << sum << std::endl;
    std::cout << ((isPrime) ? "YES" : "NO");

    return 0;
}