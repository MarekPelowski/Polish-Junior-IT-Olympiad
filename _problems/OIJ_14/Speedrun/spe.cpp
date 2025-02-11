#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int T[100000], P[100005];
bool visited[100005];

pair <long long, int> dfs(int x) {
    if(!visited[x]) {
        visited[x] = true;
        auto sum = dfs(P[x]);
        if(sum.second == x)
            return {sum.first + x, -1};
        else if(sum.second == -1)
            return {sum.first, -1};
        return {sum.first + x, sum.second};
    }
    return {0, x};
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> T[i];

    for(int i = 0; i < N; i++) {
        P[T[i]] = T[T[i] - 1];
    }
 
    long long ans = 1e18;

    for(int i = 0; i < N; i++) {
        auto sum = dfs(T[i]);
        if(sum.second == -1)
            ans = min(ans, sum.first);
    }

    cout << ans << "\n";

    return 0;
}