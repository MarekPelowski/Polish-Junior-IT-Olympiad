#include <bits/stdc++.h>
using namespace std;

const int MAXA = 1e5;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> freq(MAXA+1);
	for(int i = 0; i < n; i++) {
		int a;
		cin >> a;
		freq[a]++;
	}
	
	vector<long long> dp(MAXA+1);
	for(int i = 1; i <= MAXA; i++) {
		long long dp1 = (i-2 >= 0) ? dp[i-2] : 0;
		long long dp2 = (i-3 >= 0) ? dp[i-3] : 0;
		dp[i] = max(dp1, dp2) + (long long)freq[i] * i;
	}
	
	cout << max(dp[MAXA], dp[MAXA-1]) << "\n";
	
	return 0;
}
