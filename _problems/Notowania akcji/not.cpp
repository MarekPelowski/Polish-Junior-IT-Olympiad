#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    vector <int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];

    cin >> Q;
    vector <int> K(Q);
    for(int i = 0; i < Q; i++)
        cin >> K[i];

    int streak = 1;
    unordered_map <int, int> streaks;
    for(int i = 1; i < N; i++) {
        if(A[i] > A[i-1])
            streak++;
        else {
            streaks[streak]++;
            streak = 1;
        }
    }
    streaks[streak]++;

    return 0;
}