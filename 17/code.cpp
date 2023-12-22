#include <iostream>

int main()
{
    int A, B, C;
    std::cin >> A >> B >> C;

    int oldA = A;
    int oldB = B;

    int ways = 0;


    while(A < C && B < C){
        if(A == B){
            ways++;
            A += oldA;
        }
        else{
            int smaller = (A < B) ? A : B;
            if(smaller == A){
                A += oldA;
            }
            else{
                B += oldB;
            }
        }
    }

    std::cout << ways;

    return 0;
}