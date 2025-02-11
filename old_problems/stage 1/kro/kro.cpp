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

std::string findDiagonal(int part){
    if(part == 1) return "NW";
    if(part == 2) return "NE";
    if(part == 3) return "SW";
    if(part == 4) return "SE";
    return 0;
}

int findPath(int part, std::vector<std::string> &moves, int x1, int x2, int y1, int y2) {
    int count = 0;

    while(x1 != x2 && y1 != y2) {
        moves.push_back(findDiagonal(part));
        if(part == 1){ x1--; y1++; }
        else if(part == 2){ x1++; y1++; }
        else if(part == 3){ x1--; y1--; }
        else if(part == 4){ x1++; y1--; }

        count++;
    }
    if(y1 == y2) {
        while(x1 != x2) {
            count++;
            if(part == 1 || part == 3) { x1--; moves.push_back("W"); }
            else if (part == 2 || part == 4) { x1++; moves.push_back("E"); }
        }
    } else if (x1 == x2) {
        while(y1 != y2) {
            count++;
            if(part == 1 || part == 2) { y1++; moves.push_back("N"); }
            else if (part == 3 || part == 4) { y1--; moves.push_back("S"); }
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

    x1 = (STRxy1[0] - 'a') + 1;
    x2 = (STRxy2[0] - 'a') + 1;
    y1 = (STRxy1[1] - '1') + 1;
    y2 = (STRxy2[1] - '1') + 1;

    int part = findPart(x1, x2, y1, y2);
    std::cout << findPath(part, moves, x1, x2, y1, y2) << std::endl;

    for(int i = 0; i < moves.size(); i++){
        std::cout << moves[i] << " ";
    }

    return 0;
}