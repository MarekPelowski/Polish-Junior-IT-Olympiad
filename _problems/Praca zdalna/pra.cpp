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
    
    int left = 10e8, right = 0;

    for(const auto& pair : workTimes){
        left = std::min(left, pair.second);
        right = std::max(right, pair.first);
    }
    int minDiff = 10e4; // minimal left-right difference
    int ansPlace = -1, ans = 0;

    while(left < right){
        int mid = (left + right + 1) / 2;
        int midBalance = balance(workTimes, mid);

        if(midBalance >= 0){
            left = mid;
            if(midBalance < minDiff){
                minDiff = midBalance;
                ansPlace = mid;
            }
        }
        else {
            right = mid - 1;
            if(-midBalance < minDiff){
                minDiff = -midBalance;  
                ansPlace = mid;
            }
        }
    }

    for(const auto& pair : workTimes){
        if(pair.second < ansPlace)
            ans += ansPlace - pair.second;
        else if(pair.first > ansPlace)
            ans += pair.first - ansPlace;
    }

    std::cout << ansPlace << " " << ans << '\n';

    return 0;
}