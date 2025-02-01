#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(vector<bool> &visited, vector<vector<int>> A, int x) {
  visited[x] = true;
  for(int x2 : A[x]) {
    if(!visited[x2]) {
      dfs(visited, A, x2);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<vector<int>> A(N+1);
  vector<bool> visited(N+1);

  for(int i = 0; i < N-1; i++) {
    int u, v;
    cin >> u >> v;
    A[u].push_back(v);
    A[v].push_back(u);
  }

  vector<int> connect;

  for(int i = 1; i <= N; i++) {
    if(!visited[i]) {
      dfs(visited, A, i);
      connect.push_back(i);
    }
  }

  cout << connect.size() - 1 << "\n";

  return 0;
}