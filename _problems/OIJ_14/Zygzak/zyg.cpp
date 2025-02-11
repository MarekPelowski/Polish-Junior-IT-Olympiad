#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int getNwd(int a, int b) {
  if(b == 0)
    return a;
  return getNwd(b, a % b);
}

int main() {
  string s;
  cin >> s;
  int p = 0, q = 0;
  for(char c : s) {
    if(c == 'G')
      p++;
    else
      q++;
  }

  int nwd = getNwd(max(p, q), min(p, q));
  p /= nwd;
  q /= nwd;

  int x = 0, y = 0;
  bool isGood = true;
  for(char c : s) {
    if(c == 'G')
      y++;
    else {
      if(y != (long long)p * x / q)
        isGood = false;
      x++;
    }
  }

  if(isGood)
    cout << p << "/" << q << "\n";
  else
    cout << "NIE" << "\n"; 

  return 0;
}