#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n+1);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	vector<int> C(n+1), R(n+2);
	
	int len = 1;
	for(int i = 0; i < n; i++) {
		if(a[i] < a[i+1]) {
			len++;
		}
		else {
			C[len]++;
			len = 1;
		}
	}
	
	
	int sum = 0;
	for(int p = n; p >= 1; p--) {
		sum += C[p];
		R[p] = R[p+1] + sum;
	}
	
	int q;
	cin >> q;
	
	while(q--) {
		int k;
		cin >> k;
		
		cout << R[k] << "\n";
	}
	
	return 0;
}
