#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
string s;

char type(int i, int b) {
	char c = '?';
	if(s[i] == 'J') {
		if(b == 0) c = 'J';
		else if(b == 1) c = 'S';
	}
	else {
		if(b == 1) c = 'J';
		else if(b == 2) c = 'S';
	}
	
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> s;
	vector<int> pref(n);
	int bal = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == 'J') bal++;
		else bal--;
		pref[i] = bal;
	}
	
	unordered_map<int,int> sufJ, sufS;
	for(int i = 3; i <= n-2; i++) {
		int suf = pref[n-1] - pref[i];
		if(s[i] == 'J') sufJ[suf] = i;
		else sufS[suf] = i;
	}
	
	int p = pref[n-1];
	int a, b;

	for(int inc=-2, i=0; inc<=2; inc+=2, i++) {
		if((p+inc)%3 == 0) {
			a = (p+inc)/3;
			b = i;
		}
	}
	
	int A = -1, B = -1;
	
	for(int i = 1; i <= n-4; i++) {
		if(pref[i-1] == a) {
			char c = type(i, b);
			if(c == '?') continue;
			
			int suf;
			if(c == 'J') suf = sufJ[a];
			else suf = sufS[a];
			
			if(i+1 < suf) {
				for(int j = i+2; j <= n-2; j++) {
					if(s[j] == c) {
						if(pref[n-1] - pref[j] == a) {
							A = i+1;
							B = j+1;
							break;
						}
					}
				}
				break;
			}
		}
	}

	if(A == -1) {
		cout << "BRAK\n";
		return 0;
	}
	
	cout << A << " " << B << "\n";
	
	return 0;
}
