#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(n+1);
	for(int i = 0; i < m; i++) {
		cin >> a[i];
	}
	
	int maxCnt = 0, cnt = 0;
	for(int i = 0; i < m; i++) {
		if(a[i] == n+1) {
			maxCnt = cnt;
		} else {
			b[a[i]] = max(b[a[i]], maxCnt) + 1;
			cnt = max(cnt, b[a[i]]);
		}
	}
	
	for(int i = 1; i <= n; i++) {
		cout << max(maxCnt, b[i]) << " ";
	}
	cout << "\n";
	
	return 0;
}
