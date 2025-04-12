#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int ans = 0;
	int zeros = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 0) {
			zeros++;
		} else {
			if(a[i] <= zeros) {
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

// 8 points;
