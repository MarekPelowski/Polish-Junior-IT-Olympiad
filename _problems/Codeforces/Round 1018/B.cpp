#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<long long> l(n), r(n);
		
		for(int i = 0; i < n; i++) {
			cin >> l[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> r[i];
		}
		
		long long base = 0;
		vector<long long> adding;
		
		for(int i = 0; i < n; i++) {
			long long mx = max(l[i], r[i]);
			long long mn = min(l[i], r[i]);
			base += mx;
			adding.push_back(mn);
		}

		sort(adding.rbegin(), adding.rend());
		
		for(int i = 0; i < k-1; i++) {
			base += adding[i];
		}
		
		cout << base + 1 << "\n";
	}
	
	return 0;
}
