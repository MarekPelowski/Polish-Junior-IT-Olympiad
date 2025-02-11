#include <iostream>
#include <string>

int main()
{
    std::string word;
    std::cin >> word;

    long long result = word.size();
    int palindrom = -1;

    for(int i = 1; i < word.size(); i++) {
        if(word[i - 1] == word[i]){
            palindrom = i;
        }
        else if(i > 1 && word[i - 2] == word[i]){
            palindrom = i - 1;
        }

        if(palindrom != -1){
            result += i - palindrom;
        } else {
            result += i;
        }
    }

    std::cout << result;

    return 0;
}