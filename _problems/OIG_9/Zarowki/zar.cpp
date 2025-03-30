#include <iostream>

using namespace std;

int n, m;
string s;

int solve() {
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '1' && (i == n-1 || s[i+1] == '0')) {
			cnt++;
		}
	}
	cnt*=2;
	if(s[0] == '1') cnt--;
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> s;
	
	cout << solve() << "\n";
	while(m--) {
		int x;
		cin >> x;
		s[x-1] = (s[x-1] == '1') ? '0' : '1';
		cout << solve() << "\n";
	}
	
	return 0;
}
