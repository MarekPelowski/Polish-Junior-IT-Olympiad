#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int MAXN = 20;
int LIM;
int n;
vector<int> a(MAXN+1);

ll sum(int mask) {
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(mask & (1 << i)) {
			ans += a[n-i-1];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	LIM = (1 << n)-1;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> dp(LIM+1);
	dp[0] = 1;
	
	for(int mask = 1; mask <= LIM; mask++) {
		if(sum(mask) < 0) continue;
		for(int i = 0; i < n; i++) {
			int bit = (1 << i);
			if(mask & bit) {
				int rest = mask ^ bit;
				dp[mask] = (dp[mask] + dp[rest]) % MOD;
			}
		}
	}
	
	cout << dp[LIM] << "\n";
	
	return 0;
}
