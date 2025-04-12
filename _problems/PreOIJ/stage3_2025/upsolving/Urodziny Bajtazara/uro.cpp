#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
int n, m;
vector<vector<int>> edges(MAXN);
vector<int> grp(MAXN);
vector<int> grpSize(MAXN);
vector<bool> visited(MAXN);

void dfs (int a, int comp) {
	if (!visited[a]) {
		visited[a] = true;
		grp[a] = comp;
		grpSize[comp]++;
		for (int b : edges[a]) {
			dfs(b, comp);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
		
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++) {
		dfs(i, i);
		if ((int) edges[i].size() != grpSize[grp[i]] - 1) {
			cout << "NIE\n";
			return 0;
		}
	}
	
	cout << "TAK\n";
	
	return 0;
}
