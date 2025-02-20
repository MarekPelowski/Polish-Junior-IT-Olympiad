#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int mxN = 1e6+20;
int n, m;
vector<int> w(mxN), z(mxN);

bool can_swap(int a, int b) { 
	if(w[a] >= z[b] || w[b] >= z[a])
		return true;
	return false;
}

void make_swap(int a, int b) {
	swap(w[a], w[b]);
	swap(z[a], z[b]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> w[i] >> z[i];
	}
	
	int cnt1 = 0, cnt2 = 0;
	int pos = m-1;
	
	while(pos > 0) {
		if(can_swap(pos, pos-1)) {
			make_swap(pos, pos-1);
		} else {
			cnt1++;
		}
		pos--;
	}
	
	pos = m-1;
	
	while(pos < n-1) {
		if(can_swap(pos, pos+1)) {
			make_swap(pos, pos+1);
		} else {
			cnt2++;
		}
		pos++;
	}
	
	cout << min(cnt1, cnt2) << "\n";
	
	return 0;
}
