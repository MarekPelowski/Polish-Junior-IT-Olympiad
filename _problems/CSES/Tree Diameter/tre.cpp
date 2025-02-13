#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mxN = 2e5+10;
vector<vector<int>> edges(mxN);
vector<int> par(mxN);
vector<int> dist(mxN);

void dfs(int a) {
	for(int b : edges[a]) {
		if(b != par[a]) {
			par[b] = a;
			dist[b] = dist[a] + 1;
			dfs(b);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	dfs(1);
	
	int max_node = 1, max_dist = 0;
	for(int i = 1; i <= n; i++) {
		if(dist[i] > max_dist) {
			max_dist = dist[i];
			max_node = i;
		}
		
		par[i] = 0;
		dist[i] = 0;
	}
	
	dfs(max_node);
	int ans = 0;
	
	for(int i = 1; i <= n; i++) {
		ans = max(ans, dist[i]);
	}
	
	cout << ans << "\n";
	
	return 0;
}
