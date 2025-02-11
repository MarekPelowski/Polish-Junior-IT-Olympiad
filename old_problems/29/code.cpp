#include <iostream>
#include <unordered_map>

int main()
{
    std::string cards;
    std::cin >> cards;

    std::unordered_map<char, int> amountOfCards;

    // the current streak of 4, 3 and 2 each type
    int c4Counter = 0,
        c3Counter = 0,
        c2Counter = 0;

    for(char card : cards){
        amountOfCards[card]++;
    }

    
    


    return 0;
}