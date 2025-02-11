#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++)
    cin >> A[i];
  sort(A.begin(), A.end());

  unordered_map<int, int> count;
  for(int i = 0; i < N; i++)
    count[A[i]]++;

  int ans = 0;

  for(int i = 0; i < N; i += count[A[i]]) {
    int removeLeft = max(0, ans - A[i] + 1);

    if(removeLeft < count[A[i]]) {
      ans -= removeLeft;
      ans += count[A[i]];
    }
  }

  cout << ans << "\n";

  return 0;
}