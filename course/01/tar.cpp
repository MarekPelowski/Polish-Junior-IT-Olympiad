#include <iostream>
#include <cmath>

long long wynikRownania(long long x, long long p){
    return pow(x, 3) + p * x;
}

long long obliczRownanie(long long p, long long q)
{
    long long zakresDol = 0,
              zakresGor = q;

    long long cel = q;

    while(zakresDol < zakresGor){

        long long srodek = (zakresDol + zakresGor) / 2;

        if(wynikRownania(srodek, p) >= cel){
            zakresGor = srodek;
        } else {
            zakresDol = srodek + 1;
        }
    }

    if(wynikRownania(zakresDol, p) == q)
        return zakresDol;

    return -1;
}

int main()
{
    long long p, q;
    std::cin >> p >> q;

    if(wynikRownania(obliczRownanie(p, q), p) == q)
        std::cout << obliczRownanie(p, q);
    else {
        std::cout << "NIE";
    }

    return 0;
}