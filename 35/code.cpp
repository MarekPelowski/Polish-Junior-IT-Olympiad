#include <iostream>
#include <set>

int findOneNum(int A, int B, int C, int D)
{   
    std::set<int> divisors;

    for(int i = 1; i * i <= C; i++){
        if(C % i == 0) {
            divisors.insert(i);
            divisors.insert(C/i);
        }
    }

    for(int i = 1; i * i <= D; i++){
        if(D % i == 0) {
            divisors.insert(i);
            divisors.insert(D/i);
        }
    }

    // for(int i = 0; i < divisors.size(); i++){
    //     int x = *std::next(divisors.begin(), i);
    //     divisors.insert((C * D) / x);
    // }

    for(auto& divisor : divisors){
        std::cout << divisor << " ";
    }

    return 0;
}

int main()
{
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;

    findOneNum(A, B, C, D);
    
    return 0;
}