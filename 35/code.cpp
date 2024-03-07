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
    if(a > std::max(A, B))
        return isChoclateish(a/smallestDivisor(a), b*smallestDivisor(a), A, B);

    if(b <= std::min(A, B))
        return 1;

    return 0;
}

int main()
{
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    std::cout << isChoclateish(std::max(C, D), std::min(C, D), A, B);

    return 0;
}