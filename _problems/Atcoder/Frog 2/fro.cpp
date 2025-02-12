#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	const int INF = 2e9;
	vector<int> dp(n, INF);
	dp[0] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = 1; j <= k; j++) {
			if(i + j < n) {
				dp[i+j] = min(dp[i+j], dp[i] + abs(a[i] - a[i+j]));
			}
		}
	}
	
	cout << dp[n-1] << "\n";
	
	return 0;
}
