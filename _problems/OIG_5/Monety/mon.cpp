#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	long long ans = 1;
	for(int i = 0; i < n; i++) {
		ans *= a[i]-i;
		ans %= MOD;
	}
	
	cout << ans << "\n";
	
	return 0;
}





