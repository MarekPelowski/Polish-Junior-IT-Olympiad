#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9+5;

int n, k;
vector<int> tree;
vector<int> depth;
vector<vector<int>> dp;
int L, R;

void dfs(int a) {
	if(L <= a && a <= R) {
		for(int i = 1; i <= 20; i++) {
			dp[a][i] = tree[a];
		}
		return;
	}
	
	dfs(2*a);
	dfs(2*a+1);
	
	
}

void dfs2(int a) {
	if(L <= a && a <= R) {
		depth[a] = 0;
		return;
	}
	dfs2(2*a);
	dfs2(2*a+1);
	depth[a] = depth[2*a]+1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	L = (1 << (n-1));
	R = (1 << n) - 1;
	tree.resize(R+1);
	depth.resize(R+1);
	dp.resize(R+1, vector<int>(21));
	
	for(int i = 1; i <= R; i++) {
		int a, b;
		cin >> a >> b;
		tree[i] = a+b;
	}
	
	dfs2(1);
	dfs(1);
	
	for(int i = 1; i <= R; i++) {
		cout << i << ":\n";
		for(int j = 0; j <= 20; j++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n\n";
	}
	
	
	return 0;
}
