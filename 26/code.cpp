

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

    std::cout << std::endl;

    int streak = 1;

    for(int i = 0; i < A.size(); i++){
        if(A[i] == A[i - 1]){
            streak++;
        } else {
            streak = 1;
        }

        if((A[i] != A[i + 1]) || (i == A.size() - 1)){

            if((i - (streak - 1)) >= A[(i - (streak - 1))]){

                if((i - (streak - 1)) - (streak - 1) < A[i]){

                    while((i - (streak - 1)) >= A[i]){
                        A.erase(A.begin());
                        i--;
                    }
                } else {
                    for(int j = 0; j < streak; j++){
                        A.erase(A.begin() + i - (streak - 1));
                        i--;  
                    }
                }
            }
        }
    }


    std::cout << A.size();

    return 0;
}