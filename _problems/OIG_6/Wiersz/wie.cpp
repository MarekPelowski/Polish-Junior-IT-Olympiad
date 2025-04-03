#include <bits/stdc++.h>
using namespace std;

string no_spaces(string s) {
	string ans = "";
	for(char c : s) {
		if(c != ' ') {
			ans.push_back(c);
		}
	}
	return ans;
}

int vowels(string s) {
	int cnt = 0;
	for(char c : s) {
		for(char v : {'a', 'e', 'i', 'o', 'u', 'y'}) {
			if(c == v) {
				cnt++;
				break;
			}
		}
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	cin.ignore();
	vector<string> a(2*n);
	for(int i = 0; i < 2*n; i++) {
		string x;
		getline(cin, x);
		a[i] = no_spaces(x);
	}
	
	int cnt = 0;
	for(int i = 0; i < 2*n; i+=2) {
		int len1 = a[i].length();
		int len2 = a[i+1].length();
		
		if(vowels(a[i]) == vowels(a[i+1]) && len1 >= k && len2 >= k) {
			bool flag = true;
			
			for(int j = 0; j < k; j++) {
				if(a[i][len1-j-1] != a[i+1][len2-j-1]) {
					flag = false;
				}
			}
			
			if(flag) {
				cnt++;
			}
		}
	}
	
	cout << cnt << "\n";
	
	return 0;
}
