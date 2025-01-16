#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<long long> a(N);
  long long max_mass = 0;
  for(int i = 0; i < N; i++) {
    cin >> a[i];
    max_mass = max(max_mass, a[i]);
  }

  sort(a.begin(), a.end());
  vector<long long> available;
  long long mass = 2;
  int ans = 0, big = 0;

  while(mass < max_mass) {
    while(a[big] < mass) {
      available.push_back(a[big]);
      big++;
    }
    if(available.size() == 0) {
      cout << "NIE\n";
      return 0;
    }

    mass += available[available.size() - 1];
    available.pop_back();
    ans++;
  }

  cout << ans << "\n";

  return 0;
}