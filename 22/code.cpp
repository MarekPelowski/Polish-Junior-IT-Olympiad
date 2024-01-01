#include <iostream>
#include <algorithm>
#include <vector>

int findBestLollypop(std::vector<int> A, int N);

int main()
{
    int N;
    
    std::cin >> N;
    std::vector<int> A(N);

    for(int i = 0; i < N; i++){
        std::cin >> A[i];
    }

    if(findBestLollypop(A, N) == 0){
        std::cout << "NIE";
    }
    else{
        std::cout << findBestLollypop(A, N);
    }

    return 0;
}

int findBestLollypop(std::vector<int> A, int N){
    int smallest = 0;
    int checkIf3 = 0;
    int counter = 0;

    for(int i = 0; i < N - 2; i++){
        for(int j = i; j < ((smallest == 0) ? N : smallest + i); j++){
            counter++;
            if(A[j] == A[i]){
                checkIf3++;
            }
            if(checkIf3 == 3){
                smallest = (smallest == 0) ? counter : std::min(smallest, counter);
                break;
            }
        }
        checkIf3 = 0;
        counter = 0;
    }

    return smallest;
}