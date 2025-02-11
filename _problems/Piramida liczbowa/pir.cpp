#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int mxK = 50;
long long N;
int K;
vector<int> pows(mxK);
vector<int> pf;

void get_pf() {
	long long N_c = N;
	
	for(int i = 2; i * i <= N_c; i++) {
		while(N_c % i == 0) {
			N_c /= i;
			pf.push_back(i);
		}
	}
	
	if(N_c != 1) {
		pf.push_back(N_c);
	}
}

int get_pows(int x) {
	vector<vector<int>> sums(x, vector<int>(K-x+1, 1));
	
	for(int i = 1; i < x; i++) {
		for(int j = 1; j < K-x+1; j++) {
			sums[i][j] = sums[i][j-1] + sums[i-1][j];
		}
	}
	
	return sums[x-1][K-x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N >> K;
	for(int i = 0; i < K; i++) {
		pows[i] = get_pows(i+1);
	}
	sort(pows.rbegin(), pows.rend());
	get_pf();
	
	
	return 0;
}
