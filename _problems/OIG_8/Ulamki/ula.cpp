#include <iostream>
#include <string>
#include <algorithm>

#define ll long long
using namespace std;

int gcd(int a, int b) {
	if(a < b) 
		swap(a, b);
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	
	// 0.(48) * 10^2 = 48.(48)
	// 0.(48) * 10^2 - 0.(48) = 10^2 * 0.(48) - 0.(48)
	// (10^2 - 1) * 0.(48) = 48
	// 0.(48) = 48/(10^2 - 1)
	
	int l = s.size(), a = 0, b = 1;
	
	for(int i = l-1; i >= 0; i--) {
		int digit = s[i] - '0';
		a += digit * b;
		b*=10;
	}
	b--;	
	int g = gcd(a, b);

	cout << a/g << "/" << b/g << "\n";
	
	return 0;
}
