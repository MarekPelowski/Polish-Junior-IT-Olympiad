#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
		
	int n, w;
	cin >> n >> w;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	
	const int INF = 2e9, mxV = 1e3;
	int max_sum = mxV * n;
	vector<int> dp(max_sum+1, INF);
	dp[0] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = max_sum; j >= 0; j--) {
			if(dp[j] != INF && dp[j] + a[i] <= w) {
				dp[j+b[i]] = min(dp[j+b[i]], dp[j] + a[i]);
			}
		}
	}

	for(int i = max_sum; i >= 0; i--) {
		if(dp[i] != INF) {
			cout << i << "\n";
			return 0;
		}
	}

	return 0;
}
