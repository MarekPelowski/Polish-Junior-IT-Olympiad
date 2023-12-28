#include <iostream>
#include <vector>

std::vector<std::string> findPath(std::string start, std::string finish);

int main()
{
    std::string start, finish;
    std::cin >> start >> finish;

    std::vector<std::string> moves = findPath(start, finish);

    std::cout << moves.size() << std::endl;
    for(int i = 0; i < moves.size(); i++){
        std::cout << moves[i] << " ";
    }

    return 0;
}

std::vector<std::string> findPath(std::string start, std::string finish){
    std::vector<std::string> moves;
    
    int rowDifference = finish[1] - start[1];
    int colDifference = finish[0] - start[0];

    if(colDifference >= 0){
        if(rowDifference >= 0){

            int border = 0;

            for(int i = 0; (i < rowDifference) && (i < colDifference); i++){
                moves.push_back("NE");
                border = i + 1;
            }

            if(colDifference == border && rowDifference != border){
                for(int i = border; i < rowDifference; i++){
                    moves.push_back("N");
                }
            }

            if(rowDifference == border && colDifference != border){
                for(int i = border; i < colDifference; i++){
                    moves.push_back("E");
                }
            }
        }
        else if(rowDifference < 0){

            int border = 0;

            int temp = rowDifference;
            rowDifference = rowDifference - (rowDifference);
            rowDifference = rowDifference - (temp);

            for(int i = 0; (i < rowDifference) && (i < colDifference); i++){
                moves.push_back("SE");
                border = i + 1;
            }

            if(colDifference == border && rowDifference != border){
                for(int i = border; i < rowDifference; i++){
                    moves.push_back("S");
                }
            }

            if(rowDifference == border && colDifference != border){
                for(int i = border; i < colDifference; i++){
                    moves.push_back("E");
                }
            } 
        }
    }
    else if(colDifference < 0){
        int temp = colDifference;
        colDifference = colDifference - (colDifference);
        colDifference = colDifference - (temp);

        if(rowDifference >= 0){

            int border = 0;

            for(int i = 0; (i < rowDifference) && (i < colDifference); i++){
                moves.push_back("NW");
                border = i + 1;
            }

            if(colDifference == border && rowDifference != border){
                for(int i = border; i < rowDifference; i++){
                    moves.push_back("N");
                }
            }

            if(rowDifference == border && colDifference != border){
                for(int i = border; i < colDifference; i++){
                    moves.push_back("W");
                }
            }
        }
        else if(rowDifference < 0){

            int border = 0;

            int temp = rowDifference;
            rowDifference = rowDifference - (rowDifference);
            rowDifference = rowDifference - (temp);

            for(int i = 0; (i < rowDifference) && (i < colDifference); i++){
                moves.push_back("SW");
                border = i + 1;
            }

            if(colDifference == border && rowDifference != border){
                for(int i = border; i < rowDifference; i++){
                    moves.push_back("S");
                }
            }

            if(rowDifference == border && colDifference != border){
                for(int i = border; i < colDifference; i++){
                    moves.push_back("W");
                }
            } 
        }
    }

    return moves;
}