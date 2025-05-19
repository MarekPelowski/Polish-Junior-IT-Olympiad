#include <bits/stdc++.h>
using namespace std;

int rand_range(int a, int b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(atoi(argv[1]));
	
	int n = rand_range(1, 10);
	cout << n << "\n";
	
	for(int i = 0; i < n; i++) {
		int a = rand_range(0, 15);
		cout << a << " ";
	}
	cout << "\n";
	
	int q = rand_range(1, 10);
	cout << q << "\n";
	
	for(int i = 0; i < q; i++) {
		int k = rand_range(1, n);
		cout << k << "\n";
	}
	
	return 0;
}
