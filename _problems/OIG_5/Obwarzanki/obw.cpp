#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mxN = 1e6+5;
int n, m;
vector<int> w(mxN), z(mxN);

int solve(int inc) {
	int pos = m+inc;
	int minW = w[m], maxZ = z[m];
	
	int cnt = 0;
	while(pos >= 0 && pos < n) {
		if(z[pos] <= minW || w[pos] >= maxZ) {
			cnt++;
		}
		else {
			minW = min(minW, w[pos]);
			maxZ = max(maxZ, z[pos]);
		}

		pos+=inc;
	}
	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	m--;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> z[i];
	}
	
	int ans1 = m - solve(-1);
	int ans2 = n-m-1 - solve(1);
	
	cout << min(ans1, ans2) << "\n";
	
	return 0;
}