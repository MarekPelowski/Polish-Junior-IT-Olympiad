#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  long long N;
  cin >> N;
  
  string ans = "S";
  for(int i = 2; i <= N; i*=2)
    ans += "+S";

  if(ans.size() > 100'000) 
    cout << "NIE\n";
  else
    cout << ans << "\n";
  
  return 0;
}

// for 18 points