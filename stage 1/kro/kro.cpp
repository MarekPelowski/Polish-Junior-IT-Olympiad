#include <iostream>
#include <vector>
#include <algorithm>

int findPart(int x1, int x2, int y1, int y2) {
    if(x2 <= x1)
        if(y2 >= y1) return 1;
        else return 3;
    else
        if(y2 >= y1) return 2;
        else return 4;
}

int changeToNumbers(char letter) {
    return (letter - 'a') + 1;
}

int findPath(int part, std::vector<std::string> &moves, int x1, int x2, int y1, int y2) {
    int count = 0;

    if(part == 1){
        while(x1 > x2 && y1 < y2) {
            moves.push_back("NW");
            x1--;
            y1++;
            count++;
        }
        if(x1 == x2 || y1 == y2) {
            return count;
        } else if (x1 == x2)
            while(y1 < y2) {
                moves.push_back("N");
                y1++;
                count++;
            }
        else {
            while(x1 > x2) {
                moves.push_back("E");
                x1++;
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int x1, y1, x2, y2;
    std::string STRxy1, STRxy2;
    std::vector<std::string> moves;

    std::cin >> STRxy1;
    std::cin >> STRxy2;

    x1 = changeToNumbers(STRxy1[0]);
    x2 = changeToNumbers(STRxy2[0]);
    y1 = (STRxy1[1] - '1') + 1;
    y2 = (STRxy2[1] - '1') + 1;

    int part = findPart(x1, x2, y1, y2);
    std::cout << findPath(part, moves, x1, x2, y1, y2) << std::endl;

    for(int i = 0; i < moves.size(); i++){
        std::cout << moves[i] << " ";
    }
    return 0;
}