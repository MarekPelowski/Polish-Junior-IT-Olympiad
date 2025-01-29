#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  unordered_map<char, bool> M;
  for(char l : S)
    M[l] = true;

  for(int l = 'A'; l <= 'Z'; l++) {
    if(!M[(char)l])
      cout << (char)l << "\n";
  }

  return 0;
}