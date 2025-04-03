#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;

int ones(int L, int R) {
	int cnt = 0;
	for (int i = L; i <= R; i++) {
		if (i < 0 || i >= n) continue;
		if (s[i] == '1' && (i == R || i == n-1 || s[i+1] == '0')) {
			cnt++;
		}
	}
	return cnt;
}

int output(int cnt) {
	return (s[0] == '1') ? 2*cnt-1 : 2*cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> s;
	
	int cnt = ones(0, n-1);
	cout << output(cnt) << "\n";
	
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		x--;
		int onesOld = ones(x-1, x+1);
		s[x] = (s[x] == '1') ? '0' : '1';
		int onesNew = ones(x-1, x+1);
		
		cnt += onesNew - onesOld;
		cout << output(cnt) << "\n";
	}
	
	return 0;
}
