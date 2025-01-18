#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin >> S;
  
  queue<char> bar1, bar2;
  int status = 0;
  for(char s : S) {
    bar1.push(s);
    if(s == ')') status++;
    else status--;
  }

  if(status != 0) {
    cout << "NIE\n";
    return 0;
  }

  status = 0;
  vector<pair<int, int>> moves;
  int R = 0;
  while(!bar1.empty() || !bar2.empty()) {
    char c1 = '-', c2 = '-';
    if(!bar1.empty()) c1 = bar1.front();
    if(!bar2.empty()) c2 = bar2.front();
    R++;

    if(c1 == ')') {
      bar1.pop();
      moves.push_back({1, 3});
      status++;
      continue;
    }

    if(c2 == ')') {
      bar2.pop();
      moves.push_back({2, 3});
      status++;
      continue;
    }

    if(c1 == '(') {
      bar1.pop();
      if(status > 0) {
        moves.push_back({1, 3});
        status--;
      } else {
        moves.push_back({1, 2});
        bar2.push('(');
      }
      continue;
    }

    bar2.pop();
    moves.push_back({2, 3});
    status--;
  }

  cout << R << "\n";
  for(auto move : moves)
    cout << move.first << " " << move.second << "\n";

  return 0;
}