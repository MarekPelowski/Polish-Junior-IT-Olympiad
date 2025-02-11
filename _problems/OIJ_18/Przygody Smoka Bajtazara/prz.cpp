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
  unordered_map<int, int> count;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    count[A[i]]++;
  }

  int MAX_N = 1'000'000;

  for(int i = 1; i <= MAX_N; i++) {
    for(int j = i - 1; j >= 0; j--) {
      if(count[j] > 0)
        count[j]--;
      else {
        cout << i << "\n";
        return 0;
      }
    }
  }

  return 0;
}