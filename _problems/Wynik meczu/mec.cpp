#include <iostream>
#include <string>

int main()
{
    std::string goals;
    std::cin >> goals;
    int A = 0, B = 0;

    for(char goal : goals){
        if(goal == 'A') A++;
        else B++;
    }
    std::cout << A << " : " << B;

    return 0;
}