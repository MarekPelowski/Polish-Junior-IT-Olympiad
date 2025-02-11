#include <iostream>

long long calculateDivision(long long n);

int main()
{
    long long n;
    std::cin >> n;

    std::cout << calculateDivision(n);

    return 0;
}

long long calculateDivision(long long n){
    long long m;

    long long divisionResult = 9 - (n % 9);

    if(((n + divisionResult) / 10) % 10 == (n / 10) % 10){
        m = n + divisionResult;
    }
    else{
        m = n - (n % 9);
    }

    return m;
}