#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	
	for(int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> A(n, vector<int>(m));
		vector<pair<long long, int>> weights(n);
	
		int cnt = m * n;
		
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				cin >> A[j][k];
				weights[j].first += A[j][k] * cnt;
				weights[j].second = j;
				cnt--;
			}
		}
		
		sort(weights.rbegin(), weights.rend());
		cnt = m * n;
		long long sum = 0;
		
		for(int j = 0; j < n; j++) {
			for(int k = 0; k < m; k++) {
				sum += A[weights[j].second][k] * cnt;
				cnt--;
			}
		}
		cout << sum << "\n";
		
	}
	
	return 0;
}
