#include <iostream>
#include <cmath>

long long solve(long long n)
{
    // Rm - Radius smallest (amount of pail for the smallest circle radius)
    long long Rs = n / 14;

    // Radius Bajometr smallest (the height of the radius of the smallest circle)
    long long RBs = std::sqrt(Rs);

    // the radius of the smallest circle is 1/12 of whole snowman so we multiply it by 12
    long long result = RBs * 12;

    return result;
}

int main()
{
    long long n;
    std::cin >> n;

    std::cout << solve(n);

    return 0;
}