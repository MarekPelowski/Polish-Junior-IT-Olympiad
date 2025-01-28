#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  int balance = 0, ans = 0;
  unordered_map<int, int> M;

  for(int i = 0; i < (int)S.size(); i++) {
    if(S[i] == '1') balance++;
    else balance--;

    if(M.find(balance) == M.end())
      M[balance] = i + 1;
    
    if(balance == 0)
      ans = max(ans, i + 1);
    else if(M.find(balance) != M.end())
      ans = max(ans, i + 1 - M[balance]);
  }
  
  cout << ans << "\n";

  return 0;
}