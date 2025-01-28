#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long N;
  cin >> N;
  vector<long long> plus(91);
  plus[1] = 2;
  plus[2] = 3;

  for(int i = 3; i <= 90; i++)
    plus[i] = plus[i-2] + plus[i-1];

  vector<int> d;
  long long N_copy = N;

  for(int i = 90; i >= 1; i--) {
    while(N_copy % plus[i] == 0) {
      N_copy /= plus[i];
      d.push_back(i);
    }
  }

  string ans = "S";
  long long mult = 1;

  for(int num : d) {
    for(int i = 0; i < num; i++)
      ans.push_back('+');
    ans.push_back('S');
    mult *= plus[num];
  }

  if(mult != N || ans.size() > 100'000)
    cout << "NIE\n";
  else
    cout << ans << "\n";

  return 0;
}