#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>

using namespace std;

const int mxN = 1012;
vector<int> x(mxN), y(mxN);
vector<vector<int>> edges(mxN);
vector<bool> visited(mxN);

double dist(int x1, int y1, int x2, int y2) {
	if(x1 > x2) swap(x1, x2);
	if(y1 > y2) swap(y1, y2);
	
	long long a = x2 - x1;
	long long b = y2 - y1;

	// a^2 + b^2 = c^2
	double c = sqrt((a*a) + (b*b));

	return c;
}

void dfs(int a, int root) {
	if(!visited[a]) {
		visited[a] = true;
		for(int b : edges[a]) {
			dfs(b, root);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, p, s;
	cin >> n >> p >> s;
	for(int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i == j) {
				continue;
			}
			
			double d = dist(x[i], y[i], x[j], y[j]);
			if(d <= s) {
				edges[i].push_back(j);
			}
		}
	}
	
	p--;
	dfs(p, p);
	
	double ans = 0;
	for(int i = 0; i < n; i++) {
		if(visited[i])
			ans = max(ans, dist(x[i], y[i], x[p], y[p]));
	}
	
	ans += s;
	cout << fixed << setprecision(3) << ans << "\n";
	
	return 0;
}
