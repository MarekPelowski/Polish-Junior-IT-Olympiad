#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> w(n+1), m(n+1);
	unordered_map<int, int> pos;
	for(int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++) {
		cin >> m[i];
		pos[m[i]] = i;
	}
	
	int ans;
	if(pos[w[n]] == 1) ans = 0;
	else ans = 1;
	
	for(int i = n-1; i >= 1; i--) {
		int city = pos[w[i]];
		int prev_city = pos[w[i+1]];
		
		if((prev_city > city && city != 1) || (prev_city == 1)) {
			ans++;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
