#include <bits/stdc++.h>
using namespace std;

const double prec = 0.0000005;
int n;
vector<pair<int, int>> a;

bool ok (double t) {
	double R = a[0].first + t * a[0].second;
	
	for (int i = 1; i < n; i++) {
		double L2 = a[i].first - t * a[i].second;
		double R2 = a[i].first + t * a[i].second;
		
		if (L2 <= R) {
			R = min(R, R2);
		}
		else {
			return false;
		}
	}
	return true;
}

double bs () {
	double L = 0, R = 1e9+1;
	
	while (abs(L - R) > prec) {
		double M = (L + R) / 2;
		
		if (ok(M)) {
			R = M;
		}
		else {
			L = M + prec;
		}
	}
	
	return R;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i].second;
	}
	
	sort(a.begin(), a.end());

	cout << fixed << setprecision(9) << bs();
	
	return 0;
}
