#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, q;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> q;
	
	while(q--) {
		int k;
		cin >> k;
		
		int cnt = 0;
		int len = 0;
		int last = -1;
		for(int j = 0; j < n; j++) {
			if(a[j] > last) {
				len++;
			}
			else {
				cnt += max(0, len - k + 1);
				len = 1;
			}
			last = a[j];
		}
		cnt += max(0, len - k + 1);
		
		cout << cnt << "\n";
	}
	
	return 0;
}
