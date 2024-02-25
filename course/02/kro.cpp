#include <iostream>

int calculateApe(int n, int d, int s)
{
    if(n < 0)
        return calculateApe(s + n, d, s);

    if(n == 0)
        return 0;

    return calculateApe(n - d, d, s) + 1;
}

int main()
{
    int n, d;
    std::cin >> n >> d;

    std::cout << calculateApe(n, d, n); // the second n will be the n that won't change

    return 0;
}