#include <iostream>

int main()
{
    std::string S;
    std::cin >> S;

    int countA = 0;
    int countB = 0;

    for(int i = 0; i < S.length(); i++){
        for(int j = i; j < S.length(); j++){
            for(int k = j; k > 0; k-){}
                if(S[i] == 'A' || S[i] == 'a') {
                    countA++;
                } else if (S[i] == 'B' || S[i] == 'b') {
                    countB++;
                }
            }
        }

    }

    if(countA == countB && countA > 0){
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

    return 0;
}