#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	vector<int> A(t);
	
	for(int i = 0; i < t; i++) {
		int n, m, b;
		cin >> n >> m;
		vector<int> a(n);
		
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		
		cin >> b;
		bool ans = true;
		
		for(int j = 0; j < n; j++) {
			int new_a = b - a[j];
			
			if(j == 0) {
				a[j] = min(a[j], new_a);
				continue;
			}
			
			int sm = min(a[j], new_a), big = max(a[j], new_a);
			
			if(sm >= a[j-1]) {
				a[j] = sm;
			} else if(big >= a[j-1]) {
				a[j] = big;
			} else {
				ans = false;
				break;
			}
		}
		
		A[i] = ans;
	}
	
	for(int i = 0; i < t; i++) {
		if(A[i]) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}
