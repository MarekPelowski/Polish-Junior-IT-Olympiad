#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> solve(int n, const vector<vector<int>> &grid, const vector<int> &b) {
	vector<vector<int>> dp_up(n, vector<int>(2));
		
	for(int i = 1; i < n; i++) {
		vector<int> dp_opts;
		
		
		for(int j = 0; j < 2; j++) {
			for(int j2 = 0; j2 < 2; j2++) {
				
				bool flag = false;
				
				for(int row = 0; row < n; row++) {
					if(dp_up[row][i-1] + j2 == dp_up[row][i] + j) {
						flag = true;
						break;
					}
				}
				
				if(flag) {
					dp_opts.push_back(INF);
				}
				else {
					int sum = 0;
					
					if(j == 1) {
						sum += b[i];
					}
					
					if(j2 == 1) {
						sum += b[i-1];
					}
					
					dp_opts.push_back(sum);
				}
			}
		}
		
		dp_up[i][0] = min(dp_opts[0], dp_opts[1]);
		dp_up[i][1] = min(dp_opts[2], dp_opts[3]);
	}
	
	return dp_up;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> grid(n, vector<int>(n));
		vector<int> a(n), b(n);
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				cin >> grid[i][j];
			}
		}
		
		for(int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0; i < n; i++) {
			cin >> b[i];
		}
		
		vector<vector<int>> ans1 = solve(n, grid, b);
		
		for(int i = 0; i < n; ++i) {
			for(int j = i + 1; j < n; ++j) {
				swap(grid[i][j], grid[j][i]);
			}
		}
		for (int i = 0; i < n; ++i) {
				reverse(grid[i].begin(), grid[i].end());
		}

		
		vector<vector<int>> ans2 = solve(n, grid, a);
		
		for(int i = 1; i < n; i++) {
			if(ans1[i][0] == ans1[i][1]) {
				cout << -1 << "\n";
				break;
			}
			else {
				
			}
		}
			
	}
	
	
	
	return 0;
}
