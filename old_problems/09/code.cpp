#include <iostream>

int greatestCommonDivisor(int a, int b);

int main()
{
    int A, B;

    std::cin >> A;
    std::cin >> B;

    std::cout << greatestCommonDivisor(A, B);

    return 0;
}

int greatestCommonDivisor(int a, int b){
    
    while(b > 0){
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}