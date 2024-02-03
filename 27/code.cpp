#include <iostream>
#include <vector>

void findDiagonals(std::vector<std::vector<int>> &histogram, int x, int y, int N){
    // left-right diagonal side

    int size = std::min(x, y);

    int oldX = x,
        oldY = y;

    for(int i = 0; i < size; i++){
        x--;
        y--;
        histogram[(N - 1) - x][y]++;
    }


    x = oldX;
    y = oldY;

    size = std::min((N - 1) - x, y);
 
    for(int i = 0; i < size; i++){
        x++;
        y--;
        histogram[(N - 1) - x][y]++;
    }

    // right-left diagonal side

    x = oldX;
    y = oldY;

    size = std::min((N - 1) - x, (N - 1) - y);

    for(int i = 0; i < size; i++){
        x++;
        y++;
        histogram[(N - 1) - x][y]++;
    }


    x = oldX;
    y = oldY;

    size = std::min(x, (N - 1) - y);

    for(int i = 0; i < size; i++){
        x--;
        y++;
        histogram[(N - 1) - x][y]++;
    }

}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> squareCords(N, std::vector<int>(2));

    for(int i = 0; i < N; i++){
        std::cin >> squareCords[i][0] >> squareCords[i][1];
        squareCords[i][0]--;
        squareCords[i][1]--;
    }

    int biggestX = 0;
    int biggestY = 0;

    for(int i = 0; i < N; i++){
        biggestX = std::max(biggestX, squareCords[i][0]);
    }

    for(int i = 0; i < N; i++){
        biggestY = std::max(biggestX, squareCords[i][1]);
    }

    std::vector<std::vector<int>> histogram(biggestX, std::vector<int>(biggestY, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(squareCords[k][0] == i && squareCords[k][1] == j){
                    histogram[(N - 1) - i][j]++;

                    int x = i;
                    int y = j;

                    findDiagonals(histogram, x, y, N);
                
                    break;
                }
            }
        }
    }

    int biggestBlock = 0;
    int finalX, finalY;


    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(squareCords[k][0] == i && squareCords[k][1] == j){
                    continue;
                }
                int tempBlock = biggestBlock;
                biggestBlock = std::max(biggestBlock, histogram[i][j]);

                if(tempBlock != biggestBlock){
                    finalX = j;
                    finalY = i;
                }
            }
        }
    }

    std::cout << biggestBlock << std::endl;
    std::cout << finalX << " " << finalY;

    return 0;
}