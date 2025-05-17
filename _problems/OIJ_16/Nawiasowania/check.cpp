#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	int n = s.size();
	
	vector<int> dp(n);
	int bal = 0;
	
	for(int i = 0; i < n; i++) {
		if(s[i] == '(') bal++;
		else bal--;
		bal = max(bal, 0);
		dp[i] = bal;
	}
	
	int cnt = 0;
	for(int i = 1; i < n; i++) {
		if(dp[i] < dp[i-1]) {
			cnt++;
		}
	}
	
	int plcs_cnt = 0;
	vector<int> plcs;
	for(int i = 1; i < n; i++) {
		if(dp[i] == 0 && dp[i-1] > 0) {
			plcs_cnt++;
			if(i == n-1 || dp[i+1] == 0) {
				plcs.push_back(plcs_cnt);
				plcs_cnt = 0;
			}
		}
	}
	
	for(int x : plcs) {
		cnt += x*(x-1)/2;
	}
	
	cout << cnt << "\n";
	
	return 0;
}
