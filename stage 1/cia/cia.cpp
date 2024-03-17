#include <iostream>
#include <algorithm>
#include <vector>

int solve(std::vector<int> numSet)
{
    int n = numSet.size();
    std::sort(numSet.begin(), numSet.begin() + n, std::greater<int>());

    int count = 0;

    for(int i = 1; i < n; i++){
        if(numSet[i - 1] == 0){
            count += (numSet[i] - numSet[i - 1]);
            numSet[i] = 0;
            continue;
        }

        if(numSet[i] >= numSet[i - 1]){
            count += (numSet[i] - numSet[i - 1]) + 1;
            numSet[i] = numSet[i - 1] - 1;
        }
    }

    return count;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> numSet(n);
    for(int i = 0; i < n; i++){
        std::cin >> numSet[i];
    }

    std::cout << solve(numSet);

    return 0;
}