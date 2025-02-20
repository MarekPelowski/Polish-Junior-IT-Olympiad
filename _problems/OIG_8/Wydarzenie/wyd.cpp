#include <iostream>
#include <vector>

using namespace std;

const int mxN = 1e6+20;
int n, k;
vector<vector<int>> edges(mxN);
vector<bool> visited(mxN);

void dfs(int a) {
	if(!visited[a]) {
		visited[a] = true;
		for(int b : edges[a]) {
			dfs(b);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		if(a != 0) {
			edges[a].push_back(i);
			edges[i].push_back(a);
		}
	}
	cin >> k;
	int ans = 0;
	
	for(int i = 0; i < k; i++) {
		int a;
		cin >> a;
		if(!visited[a]) {
			dfs(a);
			ans++;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
