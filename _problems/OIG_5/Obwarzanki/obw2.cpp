#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9+5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> z(n), w(n);
  for(int i = 0; i < n; i++) {
    cin >> w[i] >> z[i];
  }

  m--;
  int minW = w[m], maxZ = z[m];
  int cnt = 0;

  for(int i = m-1; i >= 0; i--) {
    if(maxZ <= w[i] || z[i] <= minW) {
      cnt++;
    } else {
      minW = min(minW, w[i]);
      maxZ = max(maxZ, z[i]);
    }
  }

  int ans1 = m - cnt;
  minW = w[m], maxZ = z[m];
  cnt = 0;

  for(int i = m+1; i < n; i++) {
    if(maxZ <= w[i] || z[i] <= minW) {
      cnt++;
    } else {
      minW = min(minW, w[i]);
      maxZ = max(maxZ, z[i]);
    }
  }
  
  int ans2 = n - m - 1 - cnt;

  cout << min(ans1, ans2) << "\n";

  return 0;
}