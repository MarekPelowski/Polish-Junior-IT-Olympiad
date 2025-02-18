#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		a[i] = s.length();
	}
	
	sort(a.begin(), a.end());
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < a[i]; j++) {
			cout << 'O';
		}
		cout << "\n";
	}
	
	return 0;
}
