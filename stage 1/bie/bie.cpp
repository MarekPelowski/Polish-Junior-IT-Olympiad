#include <iostream>
#include <vector>

int scm(int A, int B, int lA, int lB) // smallest common multiple
{


    return scm(A + lA, B + lB, lA, lB);
}

int solve(int A, int B, long long C)
{
    std::cout << scm(A, B, A, B) << std::endl;

    return 0;
}

int main()
{
    int A, B;
    long long C;

    std::cin >> A >> B >> C;

    std::cout << solve(A, B, C);

    return 0;
}