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

    findBestLollypop(A, N);

    return 0;
}

int findBestLollypop(std::vector<int> A, int N){
    std::vector<int> B(N, 0);
    int temp = 0;
    bool isNice = false;

    for(int i = 0; i < N; i++){
        for(int j = i - 1; j >= 0; j--){
            if(A[j] == A[i]){
                temp = (i - j) + 1;
                isNice = true;
                //std::cout << temp << std::endl << std::endl;
                break;
            }
        }
        if(isNice == true){
            for(int k = i + 1; k < N; k++){
                if(A[k] == A[i]){
                    B[i] = temp + (k - i);
                    temp = 0;
                    isNice = false;
                    break;
                }
            }
        }

        std::cout << B[i] << std::endl;
    }

    return 0;
}