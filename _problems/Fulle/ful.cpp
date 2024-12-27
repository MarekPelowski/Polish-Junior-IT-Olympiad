#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string A;
  cin >> A;
  vector <int> counter(256);
  int threes = 0, twos = 0, bonus = 0, bonus2 = 0;

  for(int x : A)
    counter[x]++; 

  for(int i = 0; i < (int)counter.size(); i++) {
    threes += counter[i] / 3;
    twos += counter[i] % 3 / 2;
    if(counter[i] % 3 % 2 == 1) {
      bonus++;
      bonus2 += (counter[i] / 3 - 1) / 2;
    } else 
      bonus2 += counter[i] / 3 / 2;
  }

  if(twos >= threes) {
    cout << threes << "\n";
    return 0;
  }

  int deletes = 0;
  while(twos < threes) {
    threes--;
    twos++;
    if(bonus > 0) {
      twos++;
      bonus--;
    } else {
      deletes++;
      if(deletes % 2 == 0 && bonus2 > 0) {
        twos++;
        bonus2--;
      }
    }
  }

  cout << threes << "\n";

  return 0;
}