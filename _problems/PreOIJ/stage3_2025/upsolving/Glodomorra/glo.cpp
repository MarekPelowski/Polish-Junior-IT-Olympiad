#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	
	int end = a[0].second;
	int cnt = 1;
	
	for(int i = 1; i < n; i++) {
		if(a[i].first <= end) {
			end = min(end, a[i].second);
		}
		else {
			cnt++;
			end = a[i].second;
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}
