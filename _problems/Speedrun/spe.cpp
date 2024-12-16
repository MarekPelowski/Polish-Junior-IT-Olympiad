#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int dfs(int x, vector <int> C, vector <bool> &visited) {  
    if(!visited[x]) {
        visited[x] = true;
        return dfs(C[x], C, visited) + x;
    } 

    return 0;
}

int main() {
    int N;
    cin >> N;
    vector <int> T(N);
    for(int i = 0; i < N; i++)
        cin >> T[i];

    vector <int> C(N + 1, 0);
    vector <bool> visited(N + 1, true);

    for(int i = 0; i < N; i++) {
        C[T[i]] = T[T[i] - 1];
        visited[C[T[i]]] = false;
    }

    int ans = 1e9;

    for(int i = 0; i < N; i++) {
        ans = min(ans, dfs(T[i], C, visited));
    }

    cout << ans << "\n";    

    return 0;
}