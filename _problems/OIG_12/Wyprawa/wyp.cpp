#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int ans = 1, max_ans = 1;
	vector<bool> up(n);
	up[0] = true;
	for(int i = 1; i < n; i++) {
		if(a[i-1] < a[i]) up[i] = true;
		else up[i] = false;
		
		if(!up[i-1] && up[i]) {
			ans = 2;
			max_ans = max(max_ans, ans);
			up[i] = true;
			continue;
		}
		if(a[i-1] == a[i]) {
			ans = 1;
			up[i] = true;
			continue;
		}
		
		ans++;
		max_ans = max(max_ans, ans);
	}
	
	cout << max_ans << "\n";
	
	return 0;
}
