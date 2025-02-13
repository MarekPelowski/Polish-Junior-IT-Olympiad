#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int mxN = 2e5+10;
vector<vector<int>> edges(mxN);
vector<int> par(mxN);
vector<int> dist(mxN), dist_n1(mxN), dist_n2(mxN);
int n, max_dist, max_node;

void dfs(int a) {
	for(int b : edges[a]) {
		if(b != par[a]) {
			par[b] = a;
			dist[b] = dist[a] + 1;
			dfs(b);
		}
	}
}

void findMaxDist() {
	max_dist = 0;
	max_node = 1;
	for(int i = 1; i <= n; i++) {
		if(dist[i] > max_dist) {
			max_dist = dist[i];
			max_node = i;
		}
		par[i] = 0;
		dist[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	
	dfs(1);
	findMaxDist();
	
	dfs(max_node);
	dist_n1 = dist;
	findMaxDist();
	
	dfs(max_node);
	dist_n2 = dist;
	findMaxDist();
	
	for(int i = 1; i <= n; i++) {
		cout << max(dist_n1[i], dist_n2[i]) << " ";
	}
	
	cout << "\n";
	
	return 0;
}
