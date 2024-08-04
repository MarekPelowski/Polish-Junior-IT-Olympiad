#include "bits/stdc++.h"

using namespace std;

int main()
{
    int N, D;
    std::cin >> N >> D;
    vector<int> X(N), C(N);
    int lastTree = 0;

    for(int i = 0; i < N; i++) std::cin >> X[i];
    for(int i = 0; i < N; i++) std::cin >> C[i];

    for(int i = 0; i < N; i++){
        if(X[i + 1] - X[i] >= D){
            lastTree = C[i];
        } else {
            
        }

    }

    return 0;
}