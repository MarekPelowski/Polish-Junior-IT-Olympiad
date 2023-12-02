#include <iostream>

int findBiggestRectangle(std::string board[], int N, int M);

int main()
{   
    int N, M;
    std::cin >> N >> M;

    std::string *board = NULL;

    board = new std::string[N];

    for(int i = 0; i < N; i++){
        std::cin >> board[i];
    }

    findBiggestRectangle(board, N, M);

    return 0;
}

int findBiggestRectangle(std::string board[], int N, int M){
    int bsum = 0;
    int sum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == 0){
                if(board[i][j] == '#'){
                    sum++;
                    if(bsum < sum){
                        bsum = sum;
                    }
                }
                else{
                    sum = 0;
                }
            }
            else{
                if(board[i][j] == '#'){
                    sum++;
                    for(int k = i - 1; k >= 0; k--){
                        if(board[k][j] == '#'){
                            sum++;
                            if(bsum < sum){
                                bsum = sum;
                            }
                        }
                    }
                    if(bsum < sum){
                        bsum = sum;
                    }
                }
                else{
                    sum = 0;
                }
            }
        }
    }
    std::cout << bsum << " ";

    return 0;
}