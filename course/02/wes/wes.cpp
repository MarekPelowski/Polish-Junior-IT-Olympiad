#include <iostream>
#include <vector>

int calculateApe(int n, int d, int s)
{
    if(n % d == 0){
        return n / d;
    }

    return calculateApe(s + (n % d), d, s) + n / d;
}

int main()
{
    int z, n, d;
    std::cin >> z;

    std::vector<int> results;
    for(int i = 0; i < z; i++){
        std::cin >> n;
        std::cin >> d;
        results.push_back(calculateApe(n, d, n));
    }

    for(int i = 0; i < z; i++){
        std::cout << results[i] << std::endl;
    }


    return 0;
}