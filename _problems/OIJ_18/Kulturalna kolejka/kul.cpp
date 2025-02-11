#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;

  int seperate = 0; // how many rounds does the last space need to be seperated
  int last_index = N;
  S.push_back('.');

  for(int i = N - 1; i >= 0; i--) {
    if(S[i] == 'X') {
      if(S[i] == S[i + 1])
        seperate++;
      else {
        int empty = last_index - i - 1;
        int move = min(max(0, empty - 1), seperate);
        if(move > 0) {
          S[i] = '.';
          S[i + move] = 'X';
          last_index = i + move;
          continue;
        }
      }
      last_index = i;
    }
  }

  cout << seperate + N - last_index << "\n";

  return 0;
}