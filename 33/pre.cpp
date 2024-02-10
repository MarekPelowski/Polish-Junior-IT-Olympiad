#include <iostream>

int main()
{
    std::string letters;
    std::cin >> letters;

    int iCounter = 0,
        oCounter = 0,
        jCounter = 0,
        eCounter = 0;
    

    for(char letter : letters){
        if(letter == 'I') iCounter++;
        else if(letter == 'O') oCounter++;
        else if(letter == 'J') jCounter++;
        else if(letter == 'E') eCounter++;
    }

    if(oCounter >= 1 && iCounter >= 1 && jCounter >= 1) std::cout << 'T';
    else std::cout << 'N';

    if(oCounter >= 1 && iCounter >= 1 && jCounter >= 1 && eCounter >= 1) std::cout << 'T';
    else std::cout << 'N';

    if(iCounter >= 2 && oCounter >= 1) std::cout << 'T';
    else std::cout << 'N';

    return 0;
}