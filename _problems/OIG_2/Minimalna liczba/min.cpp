#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	long long k;
	cin >> n >> k;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<long long> b = {0};
	for(int i = 0; i < n; i++) {
		if(a[i] % k == 0) {
			b.push_back(a[i]);
		}
	}
	
	sort(b.begin(), b.end());
	
	for(int i = 1; i < (int) b.size(); i++) {
		if(b[i] != b[i-1] + k) {
			cout << b[i-1] + k << "\n";
			return 0;
		}
	}
	
	cout << b[(int) b.size()-1] + k << "\n";
	
	return 0;
}
