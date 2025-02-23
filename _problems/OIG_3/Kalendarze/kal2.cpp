#include <iostream>
#include <vector>

using namespace std;

int bs(long long days, vector<long long> pref) {
	int L = 0, R = pref.size()-1;
	
	while(L < R) {
		int mid = (L + R + 1) / 2;
		
		if(pref[mid] < days) {
			L = mid;
		} else {
			R = mid - 1;
		}
	}
	
	return L;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, z;
	cin >> n >> m;
	vector<int> A(n), B(m);
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < m; i++) cin >> B[i];
	cin >> z;
	
	vector<long long> pref_A(n+1), pref_B(m+1);
	for(int i = 1; i <= n; i++) {
		pref_A[i] = pref_A[i-1] + A[i-1];
	}
	for(int i = 1; i <= m; i++) {
		pref_B[i] = pref_B[i-1] + B[i-1];
	}
	
	for(int i = 0; i < z; i++) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		
		int days, day, month;
		if(c == 'A') {
			days = pref_A[y-1] + x;
			month = bs(days, pref_B) + 1;
			day = days - pref_B[month-1];
		} else {
			days = pref_B[y-1] + x;
			month = bs(days, pref_A) + 1;
			day = days - pref_A[month-1];
		}
		
		cout << day << " " << month << "\n";
	}
	
	return 0;
}
