#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		string s;
		cin >> n >> s;
		
		for(int i = 1; i <= n; i++) {
			int maxS = i;
			int minS = i;
			vector<int> cur(n);
			cur[0] = i;
			bool flag = false;
			
			for(int j = 0; j < n-1; j++) {
				int next;
				
				if(s[j] == '<') {
					next = minS - 1;
					minS--;
				}
				else {
					next = maxS + 1;
					maxS++;
				}
				
				if(next < 1 || next > n) {
					flag = true;
					break;
				}
				
				cur[j+1] = next;
			}
			
			if(!flag) {
				 for(int j = 0; j < n; j++) {
					 cout << cur[j] << " ";
				 }
				 cout << "\n";
				 break;
			}
		}
	}
	
	return 0;
}
