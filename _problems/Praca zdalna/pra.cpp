#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int balance(std::vector<std::pair<int, int>> workTimes, int num)
{
    int left = 0, right = 0;

    for(const auto& pair : workTimes){
        if(pair.second < num)
            left++;
        else if(pair.first > num)
            right++;
    }

    return right - left;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> workTimes(N);

    for(int i = 0; i < N; i++)
        std::cin >> workTimes[i].first >> workTimes[i].second;

    std::sort(workTimes.begin(), workTimes.end());

    int left = 10e8;
    int right = workTimes[N - 1].first;

    for(const auto& pair : workTimes)
        left = std::min(left, pair.second);

    while(left < right){
        int mid = (left + right + 1) / 2;
        
        if(balance(workTimes, mid) <= 0)
            right = mid;
        else
           left = mid;
        

        break;

    }
    

    return 0;
}