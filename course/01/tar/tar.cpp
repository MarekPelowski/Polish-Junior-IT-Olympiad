#include <iostream>

int calculateApe(int n, int d, int s)
{
    if(n % d == 0)
        return 1;

    return calculateApe(s + n % d, d, s) + 1;
}

int main()
{
    int n, d;
    std::cin >> n >> d;

    std::cout << calculateApe(n, d, n); // the second n will be the n that won't change

    return 0;
}