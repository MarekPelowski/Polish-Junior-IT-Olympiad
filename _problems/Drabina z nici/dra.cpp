#include <iostream>
#include <vector>

using namespace std;

bool visited[500010];
vector <int> counter(200010);
vector <vector <int>> path(200010);

pair<int, int> findChildren(int node) {
  vector <int> children;
  for(int i = 0; i < 3; i++) {
    int child = path[path[node][0]][i];
    if(child != node) children.push_back(child);
  }
  return {children[0], children[1]};
}

void dblDFS(int node1, int node2) {
  cout << node1 << " " << node2 << "\n";
  visited[node1] = true;
  visited[node2] = true;

  int newNode1 = -1, newNode2 = -1;
  for(int x : path[node1]) {
    if(!visited[x])
      newNode1 = x;
  }
  for(int x : path[node2]) {
    if(!visited[x])
      newNode2 = x;
  }
  if(newNode1 != -1 && newNode2 != -1)
    dblDFS(newNode1, newNode2);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;

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

    int parent1 = corners[0], parent2;
    int child = path[parent1][0];

    for(int i = 1; i < 4; i++) {
      pair <int, int> children = findChildren(corners[i]);
      if(children.first == child || children.second == child) {
        parent2 = corners[i];
        break;
      }
    }

    dblDFS(parent1, parent2);
  }

  return 0;
}