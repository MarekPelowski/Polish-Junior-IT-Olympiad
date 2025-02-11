#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N; // the amount of player 
    std::cin >> N;

    int C = 0; // the counter

    std::vector<int> players(N);

    for(int i = 0; i < N; i++){
        std::cin >> players[i];
    }

    std::sort(players.begin(), players.begin() + N);

    for(int i = 0; i < N - 2; i++){
        // if the difference between 1st and 3rd number from the ste is 1 or 0 than update the counter and skip iterations
        if(players[i + 2] - players[i] <= 1) {
            C++;
            i+=2;
            continue;
        // if the difference between 2nd and 3rd number from the set is 1 or 0 than don't skip the next iterations
        } else if (players[i + 2] - players[i + 1] <= 1) {
            continue;
        }
        i++; // if the next number is not worth checking, skip
    }

    std::cout << C;

    return 0;
}