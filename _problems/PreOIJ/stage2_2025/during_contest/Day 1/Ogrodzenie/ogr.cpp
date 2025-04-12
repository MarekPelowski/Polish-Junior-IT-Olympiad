#include <iostream>
#include <vector>

using namespace std;

const int INF = 2e9;

long long find_fence(vector<int> x, vector<int> y) {
	if(x.size() == 0)
		return 0;
	
	int max_x = -INF, max_y = -INF;
	int min_x = INF, min_y = INF;
	
	for(int a : x) {
		max_x = max(max_x, a);
		min_x = min(min_x, a);
	}
	for(int a : y) {
		max_y = max(max_y, a);
		min_y = min(min_y, a);
	}
	
	long long a = (long long)max_x - min_x;
	long long b = (long long)max_y - min_y;
	long long ans = 2 * a + 2 * b;
	
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> x, y;
	for(int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x.push_back(x1);
		x.push_back(x2);
		y.push_back(y1);
		y.push_back(y2);
	}
	
	long long ans1 = find_fence(x, y);
	
	x.pop_back();
	x.pop_back();
	y.pop_back();
	y.pop_back();
	
	long long ans2 = find_fence(x, y);
	
	cout << ans1 << "\n" << ans2 << "\n";
	
	return 0;
}
