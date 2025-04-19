#include <bits/stdc++.h>
using namespace std;

int MAX_N = 4e5+5;
int n;
vector<int> t(MAX_N);

bool ok(int l) {
	bool part2 = false;
	int cnt = 0;
	
	for(int i = 0; i < n; i++) {
		cnt++;
		
		if(t[i] <= l) {
			part2 = false;
			cnt = 0;
			continue;
		}
		
		if(!part2 && cnt >= l+1 && t[i] >= 2*l+1) {
			part2 = true;
			cnt = 0;
		}
		
		if(part2 && cnt >= l) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	int L = 0, R = 4e5;
	
	while(L < R) {
		int M = (L + R + 1) / 2;
		
		if(ok(M)) {
			L = M;
		}
		else {
			R = M - 1;
		}
	}
	
	cout << L << "\n";
	
	return 0;
}
