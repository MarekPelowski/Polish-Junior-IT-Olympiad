#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> getMax(vector<int> T)
{
    int N = T.size();
    // I'm using sparse table to find the max value
    vector<vector<int>> S_max((int)log2(N) + 1, std::vector<int>(N, -1)); // S[k+1][i] = min(S[k][i], S[k][i+2^k])

    for (int i = 0; i < N; i++)
        S_max[0][i] = T[i];
    for (int k = 1; k * k <= N; k++) {
        for (int i = 0; i + pow(2, k) - 1 < N; i++)
            S_max[k][i] = max(S_max[k - 1][i], S_max[k - 1][i + pow(2, k - 1)]);
    }

    return S_max;
}

vector<vector<int>> getMin(vector<int> T)
{
    int N = T.size();
    // I'm using sparse table to find the max value
    vector<vector<int>> S_min((int)log2(N) + 1, std::vector<int>(N, 1e9)); // S[k+1][i] = min(S[k][i], S[k][i+2^k])

    for (int i = 0; i < N; i++)
        S_min[0][i] = T[i];
    for (int k = 1; k * k <= N; k++) {
        for (int i = 0; i + pow(2, k) - 1 < N; i++)
            S_min[k][i] = min(S_min[k - 1][i], S_min[k - 1][i + pow(2, k - 1)]);
    }
    return S_min;
}

int getIndex(vector<int> T, int value) {
    int left = 0, right = T.size() - 1;
    
    while(left < right) {
        int mid = (left + right + 1) / 2;
        if(T[mid] <= value)
            left = mid;
        else
            right = mid - 1;
    }
    return left;
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> T;
    for (int i = 0; i < N - 2; i++) {
        int p, q;
        cin >> p >> q;
        T.push_back(make_pair(min(p, q), max(p, q)));
    }
    sort(T.begin(), T.end());
    vector<int> firsts(N - 2), seconds(N - 2);

    for(int i = 0; i < N - 2; i++) {
        firsts[i] = T[i].first;
        seconds[i] = T[i].second;
    }

    auto maxTable = getMax(seconds);
    auto minTable = getMin(seconds);

    // for(int i = 0; i < N - 2; i++) {
    //     int start = firsts[i] + 1;
    //     int end = seconds[i] - 1;

    //     int k = (int)log2(end - start + 1);
    //     int maxNum = maxTable[k][i];
    //     int minNum = minTable[k][i];

    //     cout << start << " " << end << " " << maxNum << " " << minNum << "\n";
    // }

    // int k = (int)log2(end - start + 1);
    // int maxNum = max(maxTable[k][start], maxTable[k][end - pow(2, k) + 1]);
    // int minNum = min(minTable[k][start], minTable[k][end - pow(2, k) + 1]);

    return 0;
}