#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  int N = S.size();
  unordered_map<char, int> C;
  string ans = "";

  for(char s : S)
    C[s]++;

  for(int i = 0; i < N; i++) {
    char wrong1 = '-', wrong2 = '-', l;
    int maxC = 0;

    if(i > 0)
      wrong1 = ans[i - 1];
    if(i > 1)
      wrong2 = ans[i - 2];

    for(char i = 'a'; i <= 'z'; i++) {
      if(i != wrong1 && i != wrong2) {
        if(C[i] > maxC) {
          maxC = C[i];
          l = i;
        }
      }
    }

    if(maxC == 0) break;
    C[l]--;
    ans.push_back(l);
  }

  cout << ans << "\n";

  return 0;
}