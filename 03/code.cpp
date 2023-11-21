#include <iostream>
#include <math.h>

int main()
{
    int n;
    std::cin >> n;
    
    int size = 0;
    int *arr = NULL;
    int division = 1;


    for(int i = 1; i <= n; i*=10){
        if(n / i != 0){
            size++;
        }
    }

    arr = new int[size];

    division = 1;

    for(int i = 0; i < size; i++){
        int modulus = n % (division * 10);
        modulus = modulus / division;
    
        arr[i] = modulus;

        division *= 10;
    }

    division = pow(10, size - 1);
    int num = 0;

    for(int i = 0; i < size; i++){
        arr[i] *= division;
        num += arr[i];

        division /= 10;
    }

    std::cout << num;

    return 0;
}