#include <iostream>

std::string solve(long long n)
{
    std::string text;

    int biggestDivisor = n;
    int biggestDivisor2 = n;

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
    
    if(biggestDivisor + n / biggestDivisor < 5999){
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

    for(int i = 2; i * i <= biggestDivisor * (n / biggestDivisor); i++)
        if(n % i == 0)
            biggestDivisor2 = i;


    int biggestDivisor3 = ((n / biggestDivisor) / biggestDivisor2);

    if(biggestDivisor + biggestDivisor2 + biggestDivisor3 < 6000){
        for(int i = 0; i < biggestDivisor; i++)
            text += 'O';
            
        for(int i = 0; i < biggestDivisor2; i++)
            text += 'I';

        for(int i = 0; i < biggestDivisor3; i++)
            text += 'J';

        return text;
    }

    return 0;
}

int main()
{
    long long n;
    std::cin >> n;

    std::cout << solve(n);

    return 0;
}