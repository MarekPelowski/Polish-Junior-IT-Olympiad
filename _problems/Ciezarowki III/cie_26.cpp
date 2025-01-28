#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S;
  int K;
  cin >> S >> K;
  vector<int> pos;
  int N = S.size();

  for(int i = 0; i < N; i++) {
    if(S[i] == 'X')
      pos.push_back(i);
  }

  int dist = 200'000;

  for(int i = 1; i < (int)pos.size(); i++) {
    int dist_now = pos[i] - pos[i - 1];
    dist = min(dist, dist_now);
  }

  if(dist % 2 == 0)
    cout << dist / 2 << "\n";
  else
    cout << dist / 2 << ".5\n";

  return 0;
}

// for 26 points