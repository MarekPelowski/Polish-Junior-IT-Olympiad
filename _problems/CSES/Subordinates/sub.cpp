#include <iostream>
#include <vector>

using namespace std;

int mxN = 2e5+10;
vector<vector<int>> edges(mxN);
vector<int> subo(mxN);

void dfs(int a) {
	subo[a] = 1;
	
	for(int b : edges[a]) {
		dfs(b);
		subo[a] += subo[b];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for(int i = 2; i <= n; i++) {
		int a;
		cin >> a;
		edges[a].push_back(i);
	}
	
	dfs(1);
		
	for(int i = 1; i <= n; i++) {
		cout << subo[i] - 1 << " ";
	}
	
	return 0;
}
