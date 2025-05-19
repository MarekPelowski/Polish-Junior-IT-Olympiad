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
	
	vector<int> up;
	int last = -1;
	int len = 0;
	
	for(int i = 0; i < n; i++) {
			if(a[i] > last) {
				len++;
			}
			else {
				up.push_back(len);
				len = 1;
			}
			last = a[i];
	}
	
	up.push_back(len);
	sort(up.begin(), up.end());
	int up_size = up.size();
	
	vector<int> suf(up_size);
	suf[up_size-1] = up[up_size-1];
	
	for(int i = up_size - 2; i >= 0; i--) {
		suf[i] = suf[i+1] + up[i];
	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int k;
		cin >> k;
		
		int idx = lower_bound(up.begin(), up.end(), k) - up.begin();
		
		if(idx == up_size) {
			cout << 0 << "\n";
			continue;
		}
		
		int rest_amnt = up_size - idx;
		int ans = suf[idx] - rest_amnt * k + rest_amnt;
		
		cout << ans << "\n";
	}
	
	return 0;
}
