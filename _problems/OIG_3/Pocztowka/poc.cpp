#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	long long ans = n * (n-1) / 2;
	
	vector<long long> len;
	long long curLen = 0;
	int mCnt = 0;
	
	for(int i = 0; i < n; i++) {
		if(a[i] < m) {
			curLen++;
		} else {
			len.push_back(curLen);
			curLen = 0;
			mCnt++;
		}
	}
	
	for(int i = 0; i < (int)len.size(); i++) {
		ans -= len[i] * (len[i] - 1) / 2;
	}
	ans += mCnt;
	
	cout << ans << "\n";
	
	return 0;
}
