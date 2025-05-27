#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int x, y;
	cin >> x >> y;
	
	int cnt = 0;
	
	for(int i = 1; i <= 6; i++) {
		for(int j = 1; j <= 6; j++) {
			if(i + j >= x || abs(i - j) >= y) {
				cnt++;
			}
		}
	}
	
	double prob = (double)cnt / 36.0;
	
	if(prob == cnt / 36) {
		cout << cnt / 36 << "\n";
	}
	else {
		cout << fixed << setprecision(15) << prob << "\n";
	}
	

	return 0;
}
