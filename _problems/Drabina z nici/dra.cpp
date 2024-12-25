#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector <int> counter(N+1);
  vector <vector <int>> path(N+1);

  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    counter[a]++;
    counter[b]++;
    path[a].push_back(b);
    path[b].push_back(a);
  }
  vector <int> corners;
  bool err = false;

  for(int i = 1; i <= N; i++) {
    if(counter[i] == 1) corners.push_back(i);
    else if(counter[i] != 3) err = true;
  }

  if(err || (int)corners.size() != 4)
    cout << "NIE\n";
  else {
    cout << "TAK\n";
  }

  // std::vector<int> childsPath = path[path[corners[0]][0]];
  // for(int i = 1; i < 4; i++) {
  //   for(int j = 0; j < (int)childsPath.size(); j++) {
  //     if(childsPath[j] == path[corners[i]][0])
  //   }
  // }

  

  return 0;
}