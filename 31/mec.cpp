#include <iostream>

int main()
{
    std::string goles;
    std::cin >> goles;

    int A = 0,
        B = 0;

    for(int i = 0; i < goles.length(); i++){
        if(goles[i] == 'A') 
            A++;
        else if (goles[i] == 'B')
            B++;
    }

    std::cout << A << " : " << B;

    return 0;
}