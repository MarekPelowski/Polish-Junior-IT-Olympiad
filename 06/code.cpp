#include <iostream>
#include <cmath>

int countDigits(int n);

int main()
{
    int n;
    std::cin >> n;

    int maxNum = pow(10, countDigits(n) - 1);

    std::cout << std::endl << (n % 100) % (100 / 10) << std::endl;

    std::cout << std::endl <<  (n / 1000) % (100 / 10) << "   " << (n % 100) / (100 / 10) << std::endl << std::endl;

    for(int i = 10; i != maxNum ; i*=10){
        if(i == 10){
            if((n / maxNum) != (n % i) / (i / 10)){
                std::cout << "NO #" << i << std::endl;
            }
        }
        else{
            if((n / maxNum) % (i / 10) != (n % i) / (i / 10)){
                std::cout << "NO #" << i << std::endl;
            }  
        }
        maxNum /= 10;
    }
   

    return 0;
}

int countDigits(int n){
    int count = 0;

    while(n > 0){
        count++;
        n /= 10;
    }

    return count;
}