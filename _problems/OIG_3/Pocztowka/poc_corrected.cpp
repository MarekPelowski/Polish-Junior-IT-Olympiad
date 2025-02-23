#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long n;
	long long m;
	cin >> n >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	long long ans = n * (n-1) / 2 + n; // (n * (n+1)) / 2
	long long noBig = 0;

	for(int i = 0; i < n; i++) {
		if(a[i] < m) {
			noBig++;
		} else {
			ans -= noBig * (noBig-1) / 2 + noBig;
			noBig = 0;
		}
	}
	ans -= noBig * (noBig-1) / 2 + noBig;
	
	cout << ans << "\n";
	
	return 0;
}

// This is a corrected version made after my 4h session. (messed up int with long long)