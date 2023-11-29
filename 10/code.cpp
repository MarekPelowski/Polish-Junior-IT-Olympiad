#include <iostream>

bool isPrimeNumber(int num);

int main()
{
    int N;
    std::cin >> N;

    for(int i = 2; i <= N; i++){
        if(isPrimeNumber(i)){
            std::cout << i << " ";
        }
    }

    return 0;
}

bool isPrimeNumber(int num){
    if(num < 2){
        return false;
    }

    for(int i = 2; i * i < num; i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}