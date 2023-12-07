#include <iostream>

int main()
{
    int K;
    std::string code;

    std::getline(std::cin >> std::ws, code);
    std::cin >> K;

    char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g',
                         'h', 'i', 'j', 'k', 'l', 'm', 'n',
                         'o', 'p', 'q', 'r', 's', 't', 'u',
                         'v', 'w', 'x', 'y', 'z'};


    for(int i = 0; i < code.length(); i++){
        if(code[i] == ' '){
            continue;
        }

        for(int j = 0; j < 26; j++){
            if()

            if(code[i] == alphabet[j]){
                code[i] = alphabet[j + K];
                break;
            }
        }
    }


/*
    for(int i = 0; i < code.length(); i++){
        if(code[i] == ' '){
            continue;
        }s

        for(int j = 0; j < 26; j++){
            if(code[i] == alphabet[j]){
                code[i] = alphabet[j + N];
            }
        }
    }
*/

    std::cout << code;

    return 0;
}