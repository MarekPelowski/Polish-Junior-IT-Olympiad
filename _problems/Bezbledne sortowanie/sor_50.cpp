#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long digits_pow(long long a) {
  long long ans = 1;
  while(a > 9) {
    a /= 10;
    ans *= 10;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  vector<long long> A(N);
  vector<int> f_digits;
  for(int i = 0; i < N; i++)
    cin >> A[i];
  sort(A.begin(), A.end());

  for(int i = 0; i < N; i++)
    f_digits.push_back(A[i] / digits_pow(A[i]));

  vector<int> dp(10);

  for(int i = 0; i < N; i++) {
    int fd = f_digits[i];
    int max_dp = 0;
    for(int j = fd; j >= 1; j--)
      max_dp = max(max_dp, dp[j]);

    dp[fd] = max_dp + 1;
  }

  int max_ans = 0;
  for(int i = 1; i <= 9; i++)
    max_ans = max(max_ans, dp[i]);

  cout << max_ans << "\n";

  return 0;
}