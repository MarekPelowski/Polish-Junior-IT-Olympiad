#include <bits/stdc++.h>
using namespace std;

int MAX_N = 4e5+5;
int n;
vector<int> t(MAX_N);
vector<int> lg(MAX_N);

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
	
	vector<vector<int>> st(lg[n], vector<int>(MAX_N));
	
	for(int i = 0; i < n; i++) {
		st[0][i] = t[i];
	}
	
	for(int k = 1; (1 << k) <= n; k++) {
		for(int i = 0; i < n; i++) {
			st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);
		}
	}
	
	
	
	return 0;
}
