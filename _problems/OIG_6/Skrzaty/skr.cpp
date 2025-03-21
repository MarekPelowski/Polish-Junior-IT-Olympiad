#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<int>> dp;

bool contains(const vector<int> &a, int x) {
	auto it = lower_bound(a.begin(), a.end(), x);
	
	if(it == a.end() || *it != x) return false;
	return true;
}

bool skip(int i, int dpi) {
	int avail = n - (int) dp[dpi].size();
	int cnt = 0;
	
	for(int x : a[i]) {
		if(contains(dp[dpi], x)) {
			cnt++;
		}
	}
	
	if((contains(dp[dpi], 1) && contains(a[i], 1)) || (avail != 0 && (int) a[i].size() - cnt == avail)) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	
	a.resize(m);
	dp.resize(m+1);
	
	for(int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for(int j = 0; j < k; j++) {
			int x;
			cin >> x;
			a[i].push_back(x);
		}
	}

	for(int i = 1; i <= n; i++) {
		dp[0].push_back(i);
	}
	
	int ans = m;
	int dpi = 0;
	
	for(int i = 0; i < m; i++) {
		if(skip(i, dpi)) {
			continue;
		}
		
		for(int x : a[i]) {
			if(contains(dp[dpi], x)) {
				dp[i+1].push_back(x);
			}
		}
		
		if(!contains(dp[i+1], n)) {
			ans = i;
			break;
		}
		dpi = i+1;
	}
	
	cout << ans << "\n";
	
	return 0;
}
