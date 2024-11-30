#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxNum(vector <int> T) {
    int N = T.size();
    // I'm using sparse table to find the max value
    vector <vector <int>> S((int)log2(N) + 1, std::vector <int>(N, -1)); // S[k+1][i] = min(S[k][i], S[k][i+2^k])

    for(int i = 0; i < N; i++)
        S[0][i] = T[i];

    for(int k = 1; k * k <= N; k++) {
        for(int i = 0; i + pow(2, k) - 1 < N; i++) {
            S[k][i] = min(S[k - 1][i], S[k - 1][i + pow(2, k - 1)]);
        }
    }

    for(auto vec : S) {
        for(int num : vec)
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}

int main() {
    int N;
    cin >> N;
    vector <pair<int, int>> T;
    for(int i = 0; i < N-2; i++) {
        int p, q;
        cin >> p >> q;
        T.push_back(make_pair(p, q));
        T.push_back(make_pair(q, p));
    }
    sort(T.begin(), T.end());
    vector<int> firsts, seconds;

    for(const auto& pair : T) {
        firsts.push_back(pair.first);
        seconds.push_back(pair.second);
    }

    maxNum({5, 2, 8, 14, 3, 19, 25, 13, 21});

    return 0;
}