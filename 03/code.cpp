#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int arr[3];

    int division = 1;

    for(int i = 0; i < 3; i++){
        int modulus = n % (division * 10);
        modulus = modulus / division;
    
        arr[i] = modulus;

        division *= 10;
    }

    division = 100;
    int num = 0;


    for(int i = 0; i < 3; i++){
        arr[i] *= division;
        num += arr[i];

        division /= 10;
    }

    std::cout << num;

    return 0;
}