#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<vector<int>> A(N, vector<int>(3));
	for(int i = 0; i < N; i++) {
		cin >> A[i][0] >> A[i][1] >> A[i][2];
	}
	
	vector<vector<int>> dp(N, vector<int>(3));
	for(int i = 0; i < 3; i++) {
		dp[0][i] = A[0][i];
	}
	
	for(int i = 1; i < N; i++) {
		for(int j = 0; j < 3; j++) {
			int max_j2 = 0;
			
			for(int j2 = 0; j2 < 3; j2++) {
				if(j != j2) {
					max_j2 = max(max_j2, dp[i-1][j2]);
				}
			}
			
			dp[i][j] = max_j2 + A[i][j];
		}
	}
	
	int max_ans = 0;
	for(int i = 0; i < 3; i++) {
		max_ans = max(max_ans, dp[N-1][i]);
	}
	
	cout << max_ans << "\n";
	
	return 0;
}
