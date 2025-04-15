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
	dp[1] = freq[1];
	for(int i = 2; i <= MAXA; i++) {
		dp[i] = max(dp[i-1], dp[i-2] + (long long)freq[i] * i);
	}
	
	cout << dp[MAXA] << "\n";
	
	return 0;
}
