#include <iostream>

void findBiggestRectangle(std::string board[], int N, int M);
void singleCheck(std::string board[], int &sum, int &bsum, int &i, int &j);
void multipleChecks(std::string board[], int &sum, int &bsum, int &i, int &j, int M);

int idk = 0;

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

void findBiggestRectangle(std::string board[], int N, int M){
    int sum = 0;
    int bsum = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(i == 0){
                singleCheck(board, sum, bsum, i, j);
            }
            else if(i > 0){
                multipleChecks(board, sum, bsum, i, j, M);
            }
        }
        sum = 0;
    }
    std::cout << bsum;
}

void singleCheck(std::string board[], int &sum, int &bsum, int &i, int &j){
    if(board[i][j] == '#'){
        sum++;
        if(bsum < sum){
            bsum = sum;
        }
    }
    else if(board[i][j] == '.'){
        sum = 0;
    }
}
void multipleChecks(std::string board[], int &sum, int &bsum, int &i, int &j, int M){
    if(board[i][j] == '#'){

        bool reset = false;
        int temp = sum;
        sum = 0;

        for(int k = i; k >= 0; k--){
            if(board[k][j] == '#'){
                sum++;
                if(bsum < sum){
                    bsum = sum;
                }
            }
            else if(board[k][j] == '.'){
                sum = 0;
            }
        }

        sum = 0;
 
        for(int n = j; n < M; n++){
            singleCheck(board, sum, bsum, i, n);
        }

        sum = temp;
    
        //...#
        //.#..
        //##..   <--- BŁĄD
        //##..
        //....

        if(j == M-1){
            for(int m = i; m >= 0; m--){
                if(board[m][j] == '#'){
                    if(board[m][j - 1] == '#'){
                        idk = 1;
                        sum++;
                        //std::cout << sum << " " << m << " " << j << std::endl;
                        if(bsum < sum){
                            bsum = sum;
                        }
                    }
                    else{
                        sum = 0;
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        else if(j < M-1){
            for(int m = i; m >= 0; m--){
                if(board[m][j] == '#'){
                    if(board[m][j + 1] == '#'){
                        sum++;
                        //std::cout << sum << " " << m << " " << j << std::endl;
                        if(bsum < sum){
                            bsum = sum;
                        }
                    }
                    else{
                        if(board[m][j - 1] == '#'){
                            sum++;
                            if(bsum < sum){
                                bsum = sum;
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
                else{
                    break;
                }
            }
        }
    }
    else if(board[i][j] == '.'){
        sum = 0;
    }
}