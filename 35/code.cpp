#include <iostream>

int smallestDivisor(int num)
{
    if(num % 2 == 0)
        return 2;

    int i = 3;

    while(i * i <= num){
        if(num % i == 0)
            return i;
        i+=2;
    }

    return num;
}
    

bool isChoclateish(int a, int b, int A, int B)
{
    std::cout << "1: " << a << " " << b << std::endl;

    if(std::max(a, b) <= std::max(A, B) && std::min(a, b) <= std::min(A, B))
        return 1;

    if(a > A && b*2 <= B)
        return isChoclateish(a/smallestDivisor(a), b*smallestDivisor(a), A, B);

    if(b > B && a*2 <= A)
        return isChoclateish(a*smallestDivisor(a), b/smallestDivisor(a), A, B);

    return 0;
}

int main()
{
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    std::cout << smallestDivisor(903) << std::endl << std::endl;

    std::cout << isChoclateish(std::max(C, D), std::min(C, D), std::max(A, B), std::min(A, B));

    return 0;
}