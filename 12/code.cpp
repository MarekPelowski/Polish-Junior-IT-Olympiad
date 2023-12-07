#include <iostream>

int findBiggestRectangle(std::string board[], int N, int M);
void a(std::string board[], int &i, int &j, int &sum, int &bsum);
void b(std::string board[], int &i, int &j, int &sum, int &bsum);

int repeat = 0;
int repeat2 = 0;

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

void a(std::string board[], int &i, int &j, int &sum, int &bsum){
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

void b(std::string board[], int &i, int &j, int &sum, int &bsum){

    if(board[i][j] == '#'){
        if(repeat == 1){
            sum = 0;
            repeat = 3;
            j = 0;
            a(board, i, j, sum, bsum);
        }
        sum++;
        if(bsum < sum){
            bsum = sum;
        }
        if(repeat == 0){
            for(int k = i - 1; k >= 0; k--){
                if(board[k][j] == '#'){
                    sum++;
                    if(bsum < sum){
                        bsum = sum;
                    }
                    if(board[k][j + 1] != '#' && repeat2 == 1){
                        sum = 0;
                        repeat2 = 3;
                        a(board, i, j, sum, bsum);
                    }
                    if(board[k][j + 1] == '.'){
                        repeat = 1;
                        sum = 0;
                    }
                }
                else{
                    if(board[k][j + 1] == '#'){
                        repeat2 = 1;
                        sum = 0;
                    }
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

int findBiggestRectangle(std::string board[], int N, int M){
    int bsum = 0;
    int sum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == 0){
                a(board, i, j, sum, bsum);
            }
            else{
                b(board, i, j, sum, bsum);
            }
        }
        sum = 0;
    }
    std::cout << bsum << " ";

    return 0;
}