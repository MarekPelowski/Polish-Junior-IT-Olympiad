#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool vowel(char c) {
	for(char a : {'a', 'e', 'i', 'o', 'u', 'y'}) {
		if(c == a)
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<string> s(2*n);
	for(int i = 0; i < 2*n; i++) {
		cin >> s[i];
	}
	
	int ans = 0;
	for(int i = 0; i < 2*n; i+=2) {
		int size1 = s[i].size();
		int size2 = s[i+1].size();
		
		if(size1 < k || size2 < k) {
			continue;
		}
	
		bool flag = false;
		for(int j = 1; j <= k; j++) {
			if(s[i][size1-j] != s[i+1][size2-j]) {
				flag = true;
				break;
			}
		}
		if(flag) continue;
		int cnt1 = 0, cnt2 = 0;
		
		for(int j = 0; j < size1; j++) {
			if(vowel(s[i][j])) cnt1++;
		}

		for(int j = 0; j < size2; j++) {
			if(vowel(s[i+1][j])) cnt2++;
		}

		if(cnt1 == cnt2) {
			ans++;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
