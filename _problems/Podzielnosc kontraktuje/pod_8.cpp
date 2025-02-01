#include <iostream>
#include <string>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N;
  string S;
  cin >> N >> S;

  int a = S[0] - '0';
  int b = S[1] - '0';

  if((a + b) % N == 0)
    cout << 2 << "\n" << a << " " << b << "\n";
  else if(a % N == 0)
    cout << 1 << "\n" << a << "\n";
  else if(b % N == 0)
    cout << 1 << "\n" << b << "\n";
  else
    cout << 0 << "\n";

  return 0;
}

// for 8 points