#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  string up, down;
  cin >> up >> down;
  vector<int> pos_up, pos_down;
  int C = 0, B = 0;
  for(int i = 0; i < N; i++) {
    if(up[i] == 'C') C++;
    else B++;
  }

  char up_color, down_color;
  if(C < B) {
    up_color = 'C';
    down_color = 'B';
  } else {
    up_color = 'B';
    down_color = 'C';
  }

  for(int i = 0; i < N; i++) {
    if(up[i] == up_color) pos_up.push_back(i);
    if(down[i] == down_color) pos_down.push_back(i);
  }

  long long ans = 0;

  for(int i = 0; i < (int)pos_up.size(); i++) {
    if(pos_up[i] < pos_down[i]) 
      ans += pos_down[i] - pos_up[i] + 1;
    else 
      ans += pos_up[i] - pos_down[i] + 1;
  }

  cout << ans << "\n";

  return 0;
}