#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int a) {
	for(int i = 2; i * i <= a; i++) {
		if(a % i == 0) {
			return false;
		}
	}
	return true;
}

int primes_amnt(int a) {
	
	int cnt = 0;
	
	for(int i = 2; i <= a; i++) {
		if(is_prime(i) && a % i == 0) {
			cnt+=1;
		}
	}
	
	if(is_prime(a) && a != 1)
		cnt++;
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int q;
	cin >> q;
	vector<int> l(q), r(q), k(q);
	for(int i = 0; i < q; i++) {
		cin >> l[i] >> r[i] >> k[i];
	}
	
	for(int i = 0; i < q; i++) {
		int cnt = 0;
		for(int j = l[i]; j <= r[i]; j++) {
			if(primes_amnt(j) <= k[i]) {
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
	
	
	return 0;
}
