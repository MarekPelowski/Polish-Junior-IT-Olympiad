#include <iostream>
#include <cmath>

int main()
{
    int N;
    std::cin >> N;

    int R = floor(N / 2);
    std::cout << R << std::endl;

    for(int i = 0; i < R; i++){
        std::cout << 2 << " " << i + 1 << " " << R - i << std::endl;
    }

    return 0;
}