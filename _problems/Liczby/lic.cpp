#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<long long> A(N);
  for(int i = 0; i < N; i++)
    cin >> A[i];
  sort(A.begin(), A.end());

  long long ans1 = A[0] * A[1] - A[0] - A[1];
  long long ans2 = A[N-1] * A[N-2] - A[N-1] - A[N-2];
  long long ans3 = A[0] * A[N-1] - A[0] - A[N-1];
  ans1 = max(ans1, -ans1);
  ans2 = max(ans2, -ans2);
  ans3 = max(ans3, -ans3);

  long long max_ans = 0;
  for(long long ans : {ans1, ans2, ans3})
    max_ans = max(max_ans, ans);

  cout << max_ans << "\n";

  return 0;
}