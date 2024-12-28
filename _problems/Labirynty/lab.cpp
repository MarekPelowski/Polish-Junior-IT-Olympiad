#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++)
    cin >> A[i];

  priority_queue<int> pq;
  long long sum = 0;
  int ans = 0;

  for(int i = 0; i < N; i++) {
    sum += A[i];
    if(A[i] < 0)
      pq.push(-A[i]);

    while(sum < 0) {
      sum += 2 * pq.top();
      pq.pop();
      ans++;
    }
  }

  cout << ans << "\n";

  return 0;
}