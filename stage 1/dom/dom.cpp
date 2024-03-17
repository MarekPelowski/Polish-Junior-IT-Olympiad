#include <iostream>
#include <vector>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> board(n, std::vector<char>(m, '.'));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            char sign;
            std::cin >> sign;

            if(sign == '*')
                board[i][j] = '*';
            if(sign == '#')
                board[i][j] = '#';

        }
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < m; j++){
            if(board[i][j] == '*'){
                board[i][j] = '.';
                for(int k = i; k < n; k++){
                    if(board[k][j] == '#' || board[k][j] == '*'){
                        board[k - 1][j] = '*';
                        break;
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }


    return 0;
}