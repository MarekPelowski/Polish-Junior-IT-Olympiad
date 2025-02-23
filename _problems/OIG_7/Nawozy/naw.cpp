#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, l;
	cin >> n >> l;
	string s;
	cin >> s;
	
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int D = 0;
	for(char c : s) {
		if(c == 'D') {
			D++;
		} else {
			int digit = c - '0';
			a[digit]--;
			if(a[digit] < 0) {
				cout << "NIE\n";
				return 0;
			}
		}
	}
	
	int remain = 0;
	for(int i = 1; i <= n; i++) {
		remain += a[i];
	}
	
	if(remain >= D) {
		cout << "TAK\n";
	} else {
		cout << "NIE\n";
	}
	
	return 0;
}
