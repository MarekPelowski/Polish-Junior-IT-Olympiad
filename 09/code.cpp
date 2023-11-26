#include <iostream>

int greatestCommonDivisor(int num1, int num2);

int main()
{
    int A, B;

    std::cin >> A;
    std::cin >> B;

    std::cout << greatestCommonDivisor(A, B);

    return 0;
}

int greatestCommonDivisor(int num1, int num2){
    
    int nwd;
    int smallerNum = num1 < num2 ? num1 : num2;

    for(int i = 1; i <= smallerNum; i++){
        if(num1 % i == 0 && num2 % i == 0){
            nwd = i;
        }
    }

    return nwd;
}