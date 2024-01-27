

#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A;

    for(int i = 0; i < N; i++){
        int temp;
        std::cin >> temp;
        A.push_back(temp);
    }

    std::sort(A.begin(), A.begin() + N);

    for(int i = 0; i < N; i++){
        std::cout << A[i] << " ";
    }

    std::cout << std::endl << std::endl;

    int streak = 1;
    int lastStreak = 1;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == A[i - 1]){
            streak++;
        } else {
            lastStreak = streak;
            streak = 1;
        }

        std::cout << streak;

        if((A[i] != A[i + 1]) || (i == A.size() - 1)){
            std::cout << "n";

            if((i - (streak - 1)) >= A[(i - (streak - 1))]){
                //A.erase(A.begin() + i);
                //i--;

                if((i - (streak - 1)) - (streak - 1) < streak){
                    std::cout << "y";
                }
                std::cout << "g";
            }
        }

        std::cout << "  ";
;    }

    for(int i = 0; i < A.size(); i++){
        std::cout << A[i] << " ";
    }



    return 0;
}