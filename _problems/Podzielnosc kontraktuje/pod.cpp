#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<long long> generateSums(vector<int> A) {

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string S;
  cin >> N >> S;

  long long a = 1;

  for(int i = 0; i < 18; i++)
    a *= 2;

  cout << a;

  return 0;
}