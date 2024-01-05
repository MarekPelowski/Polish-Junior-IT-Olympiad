#include <iostream>

int calculateDivision(int n);

int main()
{
    long long n;
    std::cin >> n;

    std::cout << calculateDivision(n);

    return 0;
}

int calculateDivision(int n){
    long long m;

    int divisionResult = 9 - (n % 9);

    if(((n + divisionResult) / 10) % 10 == (n / 10) % 10){
        m = n + divisionResult;
    }
    else{
        m = n - (n % 9);
    }

    return m;
}