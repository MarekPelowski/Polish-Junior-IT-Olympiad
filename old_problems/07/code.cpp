#include <iostream>
#include <vector>

int main()
{

    int n;
    std::cin >> n;

    std::vector<int> fib = {0, 1};

    for(int i = 0; i < n - 1; i++){
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    std::cout << fib[n] << std::endl;

    return 0;
}