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

  vector<int> dp(10), moves_new;
  vector<pair<int, int>> moves;

  for(int i = 0; i < N; i++) {
    int fd = f_digits[i];
    int max_dp = 0;
    int max_j = 0;
    for(int j = fd; j >= 1; j--) {
      if(dp[j] > max_dp) {
        max_dp = dp[j];
        max_j = j; 
      }
    }

    dp[fd] = max_dp + 1;
    moves.push_back({fd, max_j});
  }

  int max_ans = 0, end_with = 0;
  for(int i = 1; i <= 9; i++) {
    if(dp[i] > max_ans) {
      max_ans = dp[i];
      end_with = i;
    }
  }

  int last_digit = end_with;

  for(int i = moves.size()-1; i >= 0; i--) {
    if(moves[i].first == last_digit) {
      moves_new.push_back(last_digit);
      last_digit = moves[i].second;
    }
  }

  cout << max_ans << "\n";
  int moves_i = 0;

  for(int i = N-1; i >= 0; i--) {
    if(A[i] / digits_pow(A[i]) == moves_new[moves_i]) {
      cout << A[i] << " ";
      moves_i++;
    }
  }

  return 0;
}