#include <iostream>
#include <vector>

std::string addToOperation(int number);

int main()
{
    int n;
    std::cin >> n;

    std::string operation;

    int division = 2;

    while(n != 1){
        if(n % division == 0){
            operation += addToOperation(division);
            n /= division;
        }
        else{
            division++;
        }
    }

    for(int i = 0; i < 3; i++){
        operation.pop_back();
    }
    
    std::cout << operation;
    
    return 0;
}

std::string addToOperation(int number){
    std::string operation;

    operation += std::to_string(number);
    operation += " * ";

    return operation;
}