#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool has(const unordered_set<int> &us, int x) {
	if(us.find(x) != us.end()) {
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> a(m);
	
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int x;
			cin >> x;
			a[i].insert(x);
		}
	}
	
	unordered_set<int> dp;
	for (int i = 1; i <= n; i++) {
		dp.insert(i);
	}
	
	int ans = m;
	
	for (int i = 0; i < m; i++) {
		if (has(dp, 1) && has(a[i], 1)) {
			continue;
		}
		
		int cnt = 0;
		int avail = n - dp.size();
		
		for(int x : dp) {
			if(has(a[i], x)) {
				cnt++;
			}
		}
		
		bool err = (int) a[i].size() - cnt == avail ? true : false;
		
		if(err && avail != 0) {
			continue;
		}
		
		for (auto it = dp.begin(); it != dp.end(); ) {
			if (!has(a[i], *it)) {
				it = dp.erase(it);
			}
			else {
				it++;
			}
		}
		
		if(!has(dp, n)) {
			ans = i;
			break;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
