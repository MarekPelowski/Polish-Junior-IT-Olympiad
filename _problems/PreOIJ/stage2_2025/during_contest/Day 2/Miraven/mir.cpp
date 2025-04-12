#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, q;
	cin >> n;
	unordered_map<int, int> m;
	for(int i = 0; i < n; i++) {
		int h;
		cin >> h;
		
		int need_d = i - h;
		if(!m.count(need_d)) {
			m[need_d] = i;
		}
	}
	cin >> q;
	vector<int> a(q);
	
	for(int i = 0; i < q; i++) {
		cin >> a[i];
	}
	
	for(int i = 0; i < q; i++) {
		if(m.count(a[i])) {
			cout << m[a[i]] << "\n";
		} else {
			cout << "NIE dla wiezy! Wszystko lezy!\n";
		}
	}
	
	return 0;
}
