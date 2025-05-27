#include <bits/stdc++.h>
using namespace std;

long long rand_range(long long a, long long b) {
	return a + rand() % (b-a+1);
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	srand(atoi(argv[1]));
	
	int q = rand_range(1, 10);
	cout << q << "\n";
	
	while(q--) {
		long long a = rand_range(1, 10);
		long long b = rand_range(1, 10);
		
		cout << a << " " << b << "\n";
	}
	
	return 0;
}
