#include <iostream>

std::string solve(long long n)
{
    std::string text;

    int biggestDivisor = n;
    
    // n
    if(n < 5998){
        for(int i = 0; i < n; i++)
            text += 'O';
        
        text += "IJ";
        return text;
    }

    // sqrt(n)
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            biggestDivisor = i;
    
    if(biggestDivisor * n / biggestDivisor < 5999){
        for(int i = 0; i < biggestDivisor; i++)
            text += 'O';
        for(int i = 0; i < n / biggestDivisor; i++)
            text += 'I';

        text += "J";
        return text;
    }

    // cbrt(n)

    for(int i = 2; i * i * i <= n; i++)
        if(n % i == 0)
            biggestDivisor = i;

    for(int i = 2; i * i * i <= n; i++)
        if(n % i == 0)
            biggestDivisor = i;

    return text;
}

int main()
{
    long long n;
    std::cin >> n;

    std::cout << solve(n);

    return 0;
}