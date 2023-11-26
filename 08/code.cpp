#include <iostream>
#include <cmath>

bool isPerfectNum(int N);

int main()
{
    int a, b;
    std::cin >> a >> b;
    bool findPerfectNum = false;

    for(int i = a; i <= b; i++){
        if(isPerfectNum(i) == 1){
            std::cout << i << std::endl;
            findPerfectNum = true;
        }
    }

    if(findPerfectNum == false){
        std::cout << "NONE";
    }

    return 0;
}

bool isPerfectNum(int N){
    int sum = 0;

    for(int i = 1; i <= N / 2; i++){
        if(N % i == 0){
            sum+=i;
        }
    }

    if(sum == N){
        return true;
    }
    else{
        return false;
    }
}