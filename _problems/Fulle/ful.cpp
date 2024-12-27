#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  string A;
  cin >> A;
  int counter[256] = {};
  bool find2 = false, find3 = false;
  for(int x : A)
    counter[x]++;

  for(int x : counter) {
    if(x == 2) find2 = true;
    else if(x == 3) find3 = true; 
  }

  if(find2 && find3)
    cout << 1 << "\n";
  else
    cout << 0 << "\n";

  return 0;
}