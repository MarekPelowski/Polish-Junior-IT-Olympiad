#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	
	double x = (double)a / (double)b;
	int cand1 = a / b;
	int cand2 = cand1 + 1;
	
	if(abs(x - cand1) < abs(x - cand2)) {
		cout << cand1 << "\n";
	}
	else {
		cout << cand2 << "\n";
	}
	
	return 0;
}
