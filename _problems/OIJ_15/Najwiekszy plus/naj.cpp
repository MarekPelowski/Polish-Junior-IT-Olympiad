#include <bits/stdc++.h>
using namespace std;

int MAX_N = 4e5+5;
int n;
vector<int> t(MAX_N);
vector<int> lg(MAX_N);
vector<vector<int>> st;

int getMin(int L, int R) {
	int k = lg[R-L+1];
	int powK = (1 << k);
	
	return min(st[k][L], st[k][R-powK+1]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t[i];
	}
	
	int cur = 0;
	for(int i = 1; i <= n; i++) {
		if((1 << (cur+1)) <= i) {
			cur++;
		}
		
		lg[i] = cur; 
	}
	
	st.resize(lg[n]+1, vector<int>(MAX_N));

	for(int i = 0; i < n; i++) {
		st[0][i] = t[i];
	}
	
	for(int k = 1; (1 << k) <= n; k++) {
		for(int i = 0; i < n; i++) {
			if(i + (1 << (k-1)) < n) {
				st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);
			}
			else {
				st[k][i] = st[k-1][i];
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		int L = 0;
		int R = min({i, n-1-i, (t[i]-1) / 2}); 
		
		while(L < R) {
			int M = (L + R + 1) / 2;
			
			int minT = getMin(i-M, i+M);
			
			if(minT >= M+1) {
				L = M;
			}
			else {
				R = M - 1;
			}
		}
		
		ans = max(ans, L);
	}
	
	cout << ans << "\n";
	
	return 0;
}
