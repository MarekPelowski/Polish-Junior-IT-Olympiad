#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;

	while(q--) {
		long long a, b;
		cin >> a >> b;
		if(a < b) swap(a, b);

		int bits_a = 64 - __builtin_clzll(1ULL * a);
		int bits_b = 64 - __builtin_clzll(1ULL * b);
		int diff = bits_a - bits_b;
		a = (a >> diff);
		
		long long c = a ^ b;
		int bits_c = (c != 0) ? (64 - __builtin_clzll(1ULL * c)) : 0;
		
		cout << 2 * bits_c + diff << "\n";
	}

	return 0;v b 
}
