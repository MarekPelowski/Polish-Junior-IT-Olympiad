#include <iostream>
#include <vector>

int calculateApe(int n, int d, int s)
{
    if(n < 0)
        return calculateApe(s + n, d, s);

    if(n == 0)
        return 0;

    return calculateApe(n - d, d, s) + 1;
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