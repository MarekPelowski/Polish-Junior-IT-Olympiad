#include <iostream>
#include <vector>

std::string findWord(std::string text, int wordIndex) {
    std::string newWord = "";
    int count = 0;
    for(int i = 0; i < text.length(); i++) {
        newWord += text[i];
        if(text[i] == ' ') {
            count++;
            if(count == wordIndex) break;
            else newWord = "";
        }
    }
    return newWord;
}

int main()
{
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::vector<std::string>> names(N, std::vector<std::string>(2, ""));
    std::vector<std::string> conversation(K);

    for(int i = 0; i < N; i++)
        std::cin >> names[i][0];

    for(int i = 0; i < K; i++) 
        std::getline(std::cin >> std::ws, conversation[i]);

    for(int i = 0; i < K; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < names[j][0].length(); k++) {
                std::cout << names[j][0][k] << " ";
            }
        }
    }

    std::cout << findWord(conversation[0], 3);

    return 0; 
}