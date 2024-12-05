#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector <int> P(N);
    for(int i = 0; i < N; i++)
        cin >> P[i];
    sort(P.begin(), P.end());

    P[0]--;
    P[N - 1]++;
    for(int i = 1; i < N - 1; i++) {
        if(P[i - 1] < P[i] - 1)
            P[i]--;
        else if(P[i + 1] > P[i] + 1)
            P[i]++;
    }

    int ans = 1;
    for(int i = 1; i < N; i++) {
        if(P[i - 1] < P[i])
            ans++;
    }

    cout << ans << "\n";

    return 0;
}