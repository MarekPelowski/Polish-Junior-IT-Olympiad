#include <iostream>

int main()
{
    std::string letters;
    std::cin >> letters;

    int O = 0, I = 0, J = 0, E = 0;


    for(char letter : letters){
        if(letter == 'O') O++;
        if(letter == 'I') I++;
        if(letter == 'J') J++;
        if(letter == 'E') E++;
    }

    if(O > 0 && I > 0 && J > 0)
        std::cout << "T";
    else
        std::cout << "N";

    if(E > 0 && J > 0 && O > 0 && I > 0)
        std::cout << "T";
    else
        std::cout << "N";

    if(O > 0 && I > 1)
        std::cout << "T";
    else
        std::cout << "N";
    

    return 0;
}