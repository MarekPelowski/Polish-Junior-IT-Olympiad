#include <bits/stdc++.h>
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
	
	set<int> wait;
	vector<int> ready;
	unordered_map<int, bool> top;
	int ans = 0;	
	
	for(int i = 0; i < n; i++) {
		wait.insert(a[i]);
		auto lim = wait.find(a[i]);
		auto next_lim = next(lim);
		
		if(next_lim == wait.end() || top[*next_lim]) {
			top[*lim] = true;
			if(next_lim != wait.end()) {
				top.erase(*next_lim);
			}
		}
		else {
			auto it = wait.begin();
			if(!ready.empty() && *it < ready[ready.size()-1]) {
				break;
			}
			
			while(it != lim) {
				ready.push_back(*it);
				it = wait.erase(it);
			}
		}
		
		ans++;
	}
	
	cout << ans << "\n";
	
	return 0;
}
