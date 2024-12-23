#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void clearMap(unordered_map <char, int> &map) {
  for (auto& pair : map)
    pair.second = 0;
}

int main() {
  string S, P;
  cin >> S >> P;
  const int HALF = ((int)P.size() + 1) / 2;

  unordered_map <char, int> amntP, amntS;
  vector <int> vec;
  for(int i = 0; i < (int)P.size(); i++)
    amntP[P[i]]++;
    
  int cnt = 0, ans = 0;

  for(int i = 0; i < (int)S.size(); i++) {
    if(amntP[S[i]] == 0) {
      vec.push_back(cnt);
      cnt = 0;
      clearMap(amntS);
    } else if(amntS[S[i]] == amntP[S[i]]) {
      vec.push_back(cnt);
      clearMap(amntS);
      cnt = 1;
      amntS[S[i]]++;
    } else {
      cnt++;
      amntS[S[i]]++;
    }
  }

  for(int x : vec) {
    for(int i = HALF; i <= x; i++) {
      ans += x - i + 1;
      cout << ans << " ";
    }
  }

  cout << "\n" << ans << "\n";

  return 0;
}