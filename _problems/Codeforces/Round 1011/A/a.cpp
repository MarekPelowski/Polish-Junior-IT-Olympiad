#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool solve(int n, int k, string s) {
	string s2 = s;
	reverse(s2.begin(), s2.end());
	
	bool uni = false;
	bool same = true;
	for(int i = 0; i < n-1; i++) if(s[i] != s[i+1]) same = false;
	
	for(int i = 0; i < n; i++) {
		if(s[i] > s2[i]) break;
		if(s[i] < s2[i]) {
			uni = true;
			break;
		}
	}
	
	if(uni) return true;
	if(same) return false;
	if(k == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) {
		int n, k;
		string s;
		cin >> n >> k >> s;
		
		if(solve(n, k, s)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}
