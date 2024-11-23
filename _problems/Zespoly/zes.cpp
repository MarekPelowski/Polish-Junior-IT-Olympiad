#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  vector <int> T(N);
  for(int i = 0; i < N; i++)
    cin >> T[i];
  sort(T.begin(), T.end());
  
  int ans = 0;
  for(int i = 0; i < N-2; i++) {
    if(T[i+2] - T[i] <= 1) {
      ans++;
      i+=2;
    }
  }

  cout << ans << "\n";

  return 0;
}