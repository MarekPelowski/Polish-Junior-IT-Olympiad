#include <iostream>
#include <string>

using namespace std;

int main() {
  string w;
  cin >> w;
  int ans = 0;
  for(int i = 0; i < (int)w.size() - 1; i++){
    if(w[i] == w[i + 1])
      ans++;
  }

  cout << ans << "\n";

  return 0;
}