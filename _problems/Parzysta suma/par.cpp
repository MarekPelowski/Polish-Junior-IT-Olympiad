#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector <int> A(N);
  for(int i = 0; i < N; i++)
    cin >> A[i];

  long long sum = 0;
  int min_odd = 1000001;

  for(int i = 0; i < N; i++) {
    sum += A[i];
    if(A[i] % 2 == 1)
      min_odd = min(min_odd, A[i]);
  }

  if(sum % 2 == 1)
    sum -= min_odd;

  cout << sum << "\n";

  return 0;
}