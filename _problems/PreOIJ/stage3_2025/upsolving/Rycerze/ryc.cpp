#include <bits/stdc++.h>
using namespace std;

int getGCD(int a, int b) {
	if(b == 0) {
		return a;
	}
	return getGCD(b, a % b);
}

long long getLCM(long long a, long long b) {
	return a * b / getGCD(a, b);
}

vector<int> getDiv(int a) {
	vector<int> ans;
	
	for(int i = 1; i * i <= a; i++) {
		if(a % i == 0) {
			ans.push_back(i);
			if(i != a/i) {
				ans.push_back(a/i);
			}
		}
	}
	return ans;
}

long long getLcmInVec(const vector<int> &s, int m, int &cnt) {
	int n = s.size();
	long long lcm = 1;
	for(int i = 0; i < n; i++) {
		if(m % s[i] != 0 && m != -1) continue;
		cnt++;
		if(lcm > 1e9) lcm = -1;
		if(lcm != -1) {
			lcm = getLCM(lcm, s[i]);
		}

	}
	return lcm;
}

long long getLcmInVec(const vector<int> &s, int m) {
	int cnt = 0;
	return getLcmInVec(s, m, cnt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		vector<int> s(n);
		int maxVal = 0;
		
		for(int i = 0; i < n; i++) {
			cin >> s[i];
			maxVal = max(maxVal, s[i]);
		}
		
		long long bigLCM = getLcmInVec(s, -1);
		if(bigLCM != maxVal || bigLCM == -1) {
			cout << n << "\n";
			continue;
		}
		
		vector<int> div = getDiv(maxVal);
		int ans = 0;
		
		for(int m : div) {
			bool flag = false;
			for(int i = 0; i < n; i++) {
				if(s[i] == m) {
					flag = true;
					break;
				}
			}
			
			if(!flag) {
				int cnt = 0;
				int lcm = getLcmInVec(s, m, cnt);
				if(lcm == m) {
					ans = max(ans, cnt);
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}
