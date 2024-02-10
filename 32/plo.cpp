#include <iostream>
#include <set>
#include <vector>

int main()
{
    int N; // amount of sets
    std::cin >> N;

    std::vector<int> in;
    std::vector<int> out;

    for(int i = 0; i < N - 2; i++){
        int x, y; // the beginning and end of each fence
        std::cin >> x >> y;
        in.push_back(std::min(x, y));
        out.push_back(std::max(x, y));

    std::cout << std::endl;

    for(int i = 0; i < N; i++){
        
    }

    return 0;
}