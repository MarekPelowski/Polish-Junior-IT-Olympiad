#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> tree;
vector<vector<int>> dp;
int L, R;

void dfs(int a) {
	if(L <= a && a <= R) {
		for(int i = 1; i <= k; i++) {
			dp[a][i] = tree[a];
		}
		return;
	}
	
	dfs(2*a);
	dfs(2*a+1);
	
	for(int i = 1; i <= k; i++) {
		for(int j = 0; j < i; j++) {
			dp[a][i] = max(dp[a][i], dp[2*a][j] + dp[2*a+1][i-j-1] + tree[a]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> k;
	k /= 2;
	
	L = (1 << (n-1));
	R = (1 << n) - 1;
	tree.resize(R+1);
	dp.resize(R+1, vector<int>(k+1));
	
	for(int i = 1; i <= R; i++) {
		int a, b;
		cin >> a >> b;
		tree[i] = a+b;
	}
	
	dfs(1);
	
	cout << dp[1][k] << "\n";
	
	return 0;
}
