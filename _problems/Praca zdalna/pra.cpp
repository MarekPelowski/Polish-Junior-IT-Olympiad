#include <iostream>
#include <vector>
#include <utility>

int balance(std::vector<std::pair<int, int>> workTimes, int index)
{
    int left = 0, right = 0;

    for(const auto& pair : workTimes){
        if(pair.second < workTimes[index].first)
            left++;
        else if(pair.first > workTimes[index].second)
            right++;
    }

    return left - right;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> workTimes(N);

    for(int i = 0; i < N; i++)
        std::cin >> workTimes[i].first >> workTimes[i].second;

    std::cout << balance(workTimes, 1);

    return 0;
}