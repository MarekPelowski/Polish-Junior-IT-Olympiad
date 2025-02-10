#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	vector<string> A(t);
	for(int i = 0; i < t; i++) {
		string W;
		cin >> W;
		W.pop_back();
		W.pop_back();
		W.push_back('i');
		A[i] = W;
	}
	
	for(int i = 0; i < t; i++) {
		cout << A[i] << "\n";
	}
	
	
	return 0;
}
