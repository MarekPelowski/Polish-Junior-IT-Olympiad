#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; i++) {
		int next = (i == n-1) ? 0 : i+1;

		int w = x[next] - x[i];
		int h = y[next] - y[i];
		int gcd_wh = gcd(abs(w), abs(h));
		w /= gcd_wh;
		h /= gcd_wh;
		
		int x2 = x[i];
		int y2 = y[i];
		
		while(x2 != x[next] || y2 != y[next]) {
			cout << x2 << " " << y2 << "\n";
			x2 += w;
			y2 += h;
		}
	}
	
	return 0;
}
