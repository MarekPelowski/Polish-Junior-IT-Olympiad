#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	vector<string> A(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}
	
	for(int i = 0; i < N; i++) {
		int s_size = A[i].size();
		int ans = s_size;
		
		for(int j = 0; j < s_size-1; j++) {
			if(A[i][j] == A[i][j+1]) {
				ans = 1;
				break;
			}
		}
		
		cout << ans << "\n";
	}
	
	
	return 0;
}
