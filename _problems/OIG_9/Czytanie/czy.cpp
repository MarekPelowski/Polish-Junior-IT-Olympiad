#include <iostream>
#include <vector>

#define ll long long
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
	
	int ans = 0;
	for(int i = 0; i < n; i++) {
		int x = a[i] / 10;
		if(a[i] % 10 == 0) x--;
		ans += x;
	}
	
	cout << ans << "\n";
	
	return 0;
}
