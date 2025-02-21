#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> cars(n);
	
	// I changed this line from x(n), y(n). That was the problem of getting wrong answers.
	vector<int> x(m), y(m);
	for(int i = 0; i < n; i++) {
		cin >> cars[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
	}
	
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(cars[j] == x[i]) {
				cars[j] = y[i];
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		cout << cars[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
