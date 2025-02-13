#include <iostream>
#include <vector>

using namespace std;

const int mxN = 2e5+10;
vector<vector<int>> edges(mxN);
vector<int> par(mxN);
vector<bool> matched(mxN);
int ans = 0;

void dfs(int a) {
	for(int b : edges[a]) {
		if(b != par[a]) {
			par[b] = a;
			dfs(b);
			if(!matched[b] && !matched[a]) {
				matched[b] = true;
				matched[a] = true;
				ans++;
			}
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
	cout << ans << "\n";
	
	return 0;
}
