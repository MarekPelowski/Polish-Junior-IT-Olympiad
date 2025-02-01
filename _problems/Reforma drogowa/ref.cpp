#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void dfs(vector<bool> &visited, vector<pair<int, int>> &cycles, vector<vector<int>> A, int x, int last_x) {
  visited[x] = true;
  for(int x2 : A[x]) {
    if(!visited[x2]) {
      dfs(visited, cycles, A, x2, x);
    } else {
      if(last_x != x2) {
        cycles.push_back({x, x2});
      }
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
  vector<pair<int, int>> paths;


  for(int i = 0; i < N-1; i++) {
    int u, v;
    cin >> u >> v;
    paths.push_back({u, v});
    A[u].push_back(v);
    A[v].push_back(u);
  }

  vector<int> connect;
  vector<pair<int, int>> cycles;

  for(int i = 1; i <= N; i++) {
    if(!visited[i]) {
      dfs(visited, cycles, A, i, 0);
      connect.push_back(i);
    }
  }

  cout << "\n";

  vector<pair<int, int>> cycles_new;

  sort(cycles.begin(), cycles.end());

  for(int i = 1; i < cycles.size(); i++) {
    if(cycles[i] == cycles[i-1]){
      cycles_new.push_back(cycles[i]);
    }
  }

  cout << connect.size() - 1 << "\n";

  for(int i = 1; i < (int)connect.size(); i++) {
    int j = 1;
    for(auto path : paths) {
      if(path.first == cycles_new[i].first && path.second == cycles_new[i].second) {
        cout << j << " ";
        break;
      }
      j++;
    }
    cout << connect[0] << " " << connect[i] << "\n";
  }

  return 0;
}