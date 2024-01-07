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

    int lastNum = n % 10;
    int lastNum2 = (lastNum + (9 - (n % 9))) % 9;

    if(lastNum2 == 0) lastNum2 = 9;

    long long m = n - lastNum + lastNum2;

    return m;
}