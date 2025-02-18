#include <iostream>
#include <vector>
#include <algorithm>

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
	
	vector<ll> pref(n);
	pref[0] = a[0];
	for(int i = 0; i < n-1; i++) {
		pref[i+1] = pref[i] + a[i+1];
	}
	
	int ans = 0;
	
	for(int i = 0; i < n; i++) {
		ll pref1 = pref[i];
		for(int j = i+1; j < n; j++) {
			ll pref2 = pref[j] - pref[i];
			ll pref3 = pref[n-1] - pref[j];
			vector<ll> prefs = {pref1, pref2, pref3};
			sort(prefs.begin(), prefs.end());
			
			if(prefs[0] + prefs[1] > prefs[2]) {
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
