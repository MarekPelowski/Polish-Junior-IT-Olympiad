#include <iostream>

int findBiggestRectangle(std::string board[]);

int main()
{   
    int N, M;
    std::cin >> N >> M;

    std::string *board = NULL;

    board = new std::string[N];

    for(int i = 0; i < N; i++){
        std::cin >> board[i];
    }

    std::cout << findBiggestRectangle(board);

    return 0;
}

int findBiggestRectangle(std::string board[]){
    

    return 0;
}