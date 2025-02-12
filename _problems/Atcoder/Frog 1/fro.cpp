#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	const int INF = 2e9;
	vector<int> dp(n+1, INF);
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++) {
		if(i+1 < n)
			dp[i+1] = min(dp[i+1], dp[i] + abs(a[i] - a[i+1]));
		if(i+2 < n)
			dp[i+2] = min(dp[i+2], dp[i] + abs(a[i] - a[i+2]));
	}	
	
	cout << dp[n-1] << "\n";
	
	return 0;
}
