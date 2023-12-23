#include <iostream>

int main()
{
    std::string word1;
    std::string word2;
    std::cin >> word1 >> word2;

    bool isSame1 = false;

    for(int i = 0; i < word2.length(); i++){
        bool isSame2 = false;
        for(int j = 0; j < word1.length(); j++){
            if(word2[i] == word1[j]){
                isSame2 = true;
                break;
            }
        }
        if(isSame2 == true){
            isSame1 = true;
        }
        else{
            isSame1 = false;
            break;
        }
    }

    std::cout << ((isSame1) ? "YES" : "NO");

    return 0;
}