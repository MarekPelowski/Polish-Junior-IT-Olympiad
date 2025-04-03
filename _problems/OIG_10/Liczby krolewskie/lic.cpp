#include <bits/stdc++.h>
using namespace std;

int pop_count(int a) {
	if(a == 0) {
		return 0;
	}
	return pop_count(a/2) + a%2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while (t--) {
		int k;
		cin >> k;
		
		int bit = pop_count(k-1) % 2;
		cout << (((k-1) << 1) | bit) << "\n";
	}
	
	return 0;
}
