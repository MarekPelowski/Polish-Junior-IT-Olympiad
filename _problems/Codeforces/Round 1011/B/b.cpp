#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int mex(int a, int b) {
	int x = 0;
	while(true) {
		if(x != a && x != b) break;
		x++;
	}
	return x;
}

vector<pair<int,int>> solve(vector<int> a, int n) {
	vector<pair<int,int>> moves;
	
	if(a[n-1] == 0) {
		a[n-2] = mex(a[n-2], a[n-1]);
		a.pop_back();
		moves.push_back({n-2, n-1});
		n--;
	}
	
	int cur = a[0];
	
	for(int i = 1; i < n-2; i++) {
		cur = mex(cur, a[i]);
		moves.push_back({1, 2});
	}

	
	if(cur > 0 && a[n-2] > 0 && a[n-1] > 0) {
		moves.push_back({1, 3});
	}
	else {
		moves.push_back({1, 2});
		moves.push_back({1, 2});
	}
	
	return moves;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for(int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(int j = 0; j < n; j++) {
			cin >> a[j];
		}
		
		vector<pair<int,int>> ans = solve(a, n);
		
		cout << ans.size() << "\n";
		for(int i = 0; i < (int)ans.size(); i++) {
			cout << ans[i].first << " " << ans[i].second << "\n";
		}
	}
	
	return 0;
}
