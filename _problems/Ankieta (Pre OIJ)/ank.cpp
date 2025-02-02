#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  cin >> N;
  double days = 30.0 / N;

  if(days >= 30 / N + 0.5)
    cout << 30 / N + 1 << "\n";
  else
    cout << 30 / N << "\n";

  return 0;
}