#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define ll long long
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	vector<int> pref(n+1);
	unordered_map<int, vector<int>> suf;
	int stat = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'J') stat++;
		else stat--;
		pref[i+1] = stat;
	}
	stat = 0;
	for(int i = n-1; i > 0; i--) {
		if(s[i] == 'J') stat++;
		else stat--;
		suf[stat].push_back(i-1);
	}
	
	int A = n, B = n;
	
	for(int i = 1; i <= n-4; i++) {
		int x = pref[i];
		for(int j : suf[x]) {
			if(j > i+1 && j <= n-2) {
				int seg = pref[j] - pref[i+1];
				if(seg == x) {
					A = i+1;
					B = min(B, j+1);
				}
			}
		}
		
		if(A == i+1) {
			cout << A << " " << B << "\n";
			return 0;
		}
	}
	
	cout << "BRAK\n";
	
	return 0;
}
