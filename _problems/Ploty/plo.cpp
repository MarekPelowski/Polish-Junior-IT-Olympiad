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
    vector<pair<int, int>> singleT(N-2);
    for (int i = 0; i < N - 2; i++) {
        int p, q;
        cin >> p >> q;
        T.push_back(make_pair(p, q));
        T.push_back(make_pair(q, p));
        singleT[i] = make_pair(p, q);
    }
    sort(T.begin(), T.end());
    vector<int> firsts, seconds;

    int T_size = 2 * (N - 2);

    for(int i = 0; i < T_size; i++) {
        firsts.push_back(T[i].first);
        seconds.push_back(T[i].second);
    }

    auto maxTable = getMax(seconds);
    auto minTable = getMin(seconds);

    for(int i = 0; i < N - 2; i++) {
        int start = min(singleT[i].first, singleT[i].second) + 1;
        int end = max(singleT[i].first, singleT[i].second) - 1;

        int endIndex = getIndex(firsts, end);
        int startIndex = getIndex(firsts, start - 1) + 1;

        if(endIndex < startIndex)
            continue;

        int k = log2(end - start + 1);
        int minNum = min(minTable[k][startIndex], minTable[k][endIndex - pow(2, k) + 1]);
        int maxNum = max(maxTable[k][startIndex], maxTable[k][endIndex - pow(2, k) + 1]);

        if(minNum < start - 1 || maxNum > end + 1) {
            int wrongCount = 0;
            pair<int, int> wrong;

            for(int i = startIndex; i <= endIndex; i++) {
                if(seconds[i] < start - 1 || seconds[i] > end + 1) {
                    wrongCount++;
                    wrong = make_pair(min(firsts[i], seconds[i]), max(firsts[i], seconds[i]));
                }
            }

            if(wrongCount == 1)
                cout << wrong.first << " " << wrong.second;
            else
                cout << start - 1 << " " << end + 1;
            break;
        }
    }

    return 0;
}