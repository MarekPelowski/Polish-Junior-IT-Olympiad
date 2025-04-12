#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int mxN = 4e5+20;
vector<long long> a(mxN), b(mxN);

bool dist(long long t) {
	long long amnt = 0, last = 0;
	
	for(int i = 0; i < m; i++) {
		long long start;
		if(i == 0) {
			start = a[i];
		} else {
			start = max(last + t, a[i]);
		}
		if(start > b[i]) continue;
		
		long long len = b[i] - start + 1;
		long long cur_amnt = (len + t - 1) / t;
		last = start + (cur_amnt-1) * t;
		amnt += cur_amnt;
	}
	
	if(amnt >= n) {
		return true;
	} else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	vector<pair<long long, long long>> ab(m);
	for(int i = 0; i < m; i++) {
		cin >> ab[i].first >> ab[i].second;
	}
	sort(ab.begin(), ab.end());
	long long max_b = 0;
	
	for(int i = 0; i < m; i++) {
		a[i] = ab[i].first;
		b[i] = ab[i].second;
		max_b = max(max_b, b[i]);
	}

	
	long long left = 1, right = max_b;
	while(left < right) {
		long long mid = (left + right + 1) / 2;
		if(dist(mid)) {
			left = mid;
		} else {
			right = mid - 1;
		}
	}
	
	if(!dist(left)) {
		cout << 0 << "\n";
	} else {
		cout << left << "\n";
	}
	
	return 0;
}
