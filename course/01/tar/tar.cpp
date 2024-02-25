#include <iostream>
#include <cmath>
#include <vector>

long long wynikRownania(long long x, long long p){
    long long potega = (long long)x * (long long)x * (long long)x; // I use this code because the pow(x, 3) doesn't work with long long type

    return potega + p * x;
}

long long obliczRownanie(long long p, long long q)
int calculateApe(int n, int d, int s)
{
    long long zakresDol = 0,
              zakresGor = 1000001;  // biggest x possible.

    long long cel = q;

    int counter = 0;

    while(zakresDol < zakresGor) {
        counter++;

        long long srodek = (zakresDol + zakresGor) / 2;
    if(n % d == 0)
        return 1;

        if(wynikRownania(srodek, p) >= q) {
            zakresGor = srodek;

        } else {
            zakresDol = srodek + 1;
        }

    }

    if(wynikRownania(zakresDol, p) == q)
         return zakresDol;

    return -1;
    return calculateApe(s + n % d, d, s) + 1;
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
    int n, d;
    std::cin >> n >> d;

    for(int i = 0; i < z; i++){
        if(results[i] >= 0)
            std::cout << results[i] << std::endl;
        else
            std::cout << "NIE" << std::endl;
    }
    std::cout << calculateApe(n, d, n); // the second n will be the n that won't change

    return 0;
}