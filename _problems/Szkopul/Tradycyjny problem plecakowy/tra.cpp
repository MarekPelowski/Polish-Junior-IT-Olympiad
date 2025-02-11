#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n); // {w, u}
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	
	vector<long long> dp(k+1, -1);
	dp[0] = 0;
	
	for(int i = 0; i < n; i++) {
		for(int j = k; j >= 0; j--) {
			if(dp[j] != -1 && j+a[i].first <= k) {
				dp[j+a[i].first] = max(dp[j+a[i].first], dp[j]+a[i].second);
			}
		}
	}
	
	long long ans = 0;
	for(int i = 0; i <= k; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";

	return 0;
}

// https://szkopul.edu.pl/problemset/problem/MYTUWkTbMYi5EWkVhLLupYg2/site/?key=statement
