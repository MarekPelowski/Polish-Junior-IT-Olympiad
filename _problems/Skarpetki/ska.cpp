#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  int B = 0, C = 0;
  for(char x : S) {
    if(x == 'B') B++;
    else if(x == 'C') C++;
  }

  int ans = B/2 + C/2;

  cout << ans << "\n";

  return 0;
}