#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<long long> c(n), p(n-1);
	for(int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for(int i = 0; i < n-1; i++) {
		cin >> p[i];
	}
	
	vector<long long> pref(n);
	pref[0] = 0;
	for(int i = 1; i < n; i++) {
		pref[i] = pref[i-1] + p[i-1];
	}
	
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
		  long long dist = max(pref[i], pref[j]) - min(pref[i], pref[j]);
			long long buy = c[i];
			long long sell = c[j];
			ans = max(ans, sell - buy - dist);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
