#include <iostream>
#include <vector>

std::string findWord(std::string text, int wordIndex) {
    std::string newWord = "";
    int count = 0;
    for(int i = 0; i < text.length(); i++) {
        if(text[i] == ' ') {
            count++;
            if(count == wordIndex) break;
            else {newWord = ""; continue; }
        }
        newWord += text[i];
    }
    return newWord;
}

int main()
{
    int N, K;
    std::cin >> N >> K;
    
    std::vector<std::vector<std::string>> names(N, std::vector<std::string>(2, ""));
    std::vector<std::string> conversation(K);

    for(int i = 0; i < N; i++) {
        std::cin >> names[i][0];
        names[i][0] += ":";
    }

    for(int i = 0; i < K; i++) 
        std::getline(std::cin >> std::ws, conversation[i]);

    if(findWord(conversation[0], 3) == "orkiem.") {
        for(int i = 0; i < N; i++) {
            if(findWord(conversation[0], 1) == names[i][0]) {
                std::cout << "It works";
            }
        }
    }

    //std::cout << findWord(conversation[0], 3);

    return 0; 
}