#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<long long, int>> a(n);

	for(int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector<long long> ans(n);

	const long long INF = 1e18+500;
	for(int i = 0; i < n; i++) {
		long long min_lcm = INF;
		
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(a[j].first >= min_lcm)
				break;
			min_lcm = min(min_lcm, lcm(a[i].first, a[j].first));
		}
		
		if(min_lcm == INF) {
			ans[a[i].second] = -1;
		} else {
			ans[a[i].second] = min_lcm;
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	
	cout << "\n";
	
	return 0;
}
