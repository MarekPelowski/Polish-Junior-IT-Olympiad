#include <iostream>
#include <cmath>
#include <vector>

long long rownanie(long long p, long long x){
    return x * x * x + p * x;
}

long long findx(long long p, long long q){
    long long poczatek = 0;
    long long koniec = q;
    long long srodek;

    while(poczatek < koniec){
        srodek = poczatek + (koniec - poczatek + 1) / 2;

        if(rownanie(p, srodek) <= q){
            poczatek = srodek;
        }
        else{
            koniec = srodek - 1;
        }
    }

    std::cout << poczatek << std::endl;

    if(rownanie(p, poczatek) == q){
        return poczatek;
    }
    else{
        return -1;
    }
}


int main()
{
    int z;
    std::cin >> z;

    long long p, q;
    std::cin >> p >> q;

    //std::vector<long long> storeValues;

    std::cout << findx(p, q);

    // for(int i = 0; i < z; i++){
    //     long long p, q;
    //     std::cin >> p >> q;
    //     storeValues.push_back(findx(p, q));
    // }

    // for(int i = 0; i < z; i++){
    //     if(storeValues[i] == -1){
    //         std::cout << "NIE" << std::endl;
    //         std::cout << storeValues[i] << std::endl;
    //     }
    //     else{
    //         std::cout << storeValues[i] << std::endl;
    //     }
    // }

    return 0;
}