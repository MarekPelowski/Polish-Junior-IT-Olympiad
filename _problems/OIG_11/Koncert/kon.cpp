#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;
	int del = n-1;
	for(int i = 0; i < n-1; i++) {
		if(s[i+1] < s[i]) {
			del = i;
			break;
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(i != del) {
			cout << s[i];
		}
	}
	cout << "\n";
	
	return 0;
}
