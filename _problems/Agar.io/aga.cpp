#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getBiggest(vector<long long> a, long long b) {
  int left = 0, right = a.size() - 1;

  while(left < right) {
    int mid = (left + right + 1) / 2;

    if(a[mid] >= b)
      right = mid - 1;
    else
      left = mid;
  }

  if(a[left] >= b)
    return -1;
  return left;
}

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

  int ans = 0;
  long long mass = 2;

  while(mass < max_mass) {
    long long biggest = getBiggest(a, mass);
    if(biggest == -1) {
      cout << "NIE\n";
      return 0;
    }

    mass += a[biggest];
    a.erase(a.begin() + biggest);
    ans++;
  }

  cout << ans << "\n";

  return 0;
}