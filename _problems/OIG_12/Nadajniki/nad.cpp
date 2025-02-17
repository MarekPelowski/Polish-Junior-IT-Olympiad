#include <iostream>
#include <vector>

using namespace std;

const long long INF = 1LL << 60;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> start(m+1), end(m+1);
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		start[a] = b;
		if(a + b <= m) {
			end[a+b]++;
		}
	}
	
	int a = 0;
	vector<long long> signal(m+1);
	for(int i = 1; i <= m; i++) {
		signal[i] = signal[i-1] - a;
		if(start[i] != 0) {
			a++;
			signal[i] += start[i];
		}
		a -= end[i];
	}
	
	
	long long max_sig = 0, min_sig = INF;
	int max_pos = 0, min_pos = 0;
	
	for(int i = 1; i <= m; i++) {
		if(signal[i] > max_sig) {
			max_sig = signal[i];
			max_pos = i;
		}
		if(signal[i] < min_sig) {
			min_sig = signal[i];
			min_pos = i;
		}
	}
	
	cout << max_pos << " " << min_pos << "\n";
	
	return 0;
}
