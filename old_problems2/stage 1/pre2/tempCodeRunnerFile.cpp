#include <iostream>
#include <cmath>

int main()
{
    int N;
    std::cin >> N;

    int R = round((double)N/2);
    std::cout << R << std::endl;


    if(N % 2 == 0) {
        for(int i = 1; i <= R; i++){
            std::cout << 2 << " " << i << " " << N - i + 1 << std::endl;
        }
    } else {
        for(int i = 1; i < R; i++){
            std::cout << 2 << " " << i << " " << N - i << std::endl;
        }
        std::cout << 1 << " " << N << std::endl;

    }


    return 0;
}