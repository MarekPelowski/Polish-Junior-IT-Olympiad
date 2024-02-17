#include <iostream>
#include <cmath>
#include <vector>

long long wynikRownania(long long x, long long p){
    return pow(x, 3) + p * x;
}

long long obliczRownanie(long long p, long long q)
{
    long long zakresDol = 0,
              zakresGor = 1000001;  // biggest x possible.

    long long cel = q;

    int counter = 0;

    while(zakresDol < zakresGor) {
        counter++;

        long long srodek = (zakresDol + zakresGor) / 2;

        std::cout << wynikRownania(srodek, p) << "   " << zakresDol << "   " << srodek << "   " << zakresGor << std::endl;

        if(wynikRownania(srodek, p) >= q) {
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
    int z;
    std::cin >> z;

    std::vector<long long> results;

    for(int i = 0; i < z; i++){
        long long p, q;
        std::cin >> p >> q;

        results.push_back(obliczRownanie(p, q));
    }

    for(int i = 0; i < z; i++){
        if(results[i] >= 0) 
            std::cout << results[i] << std::endl;
        else
            std::cout << "NIE" << std::endl;
    }

    return 0;
}