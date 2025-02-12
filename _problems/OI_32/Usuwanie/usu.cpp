#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long a, b;
	cin >> a >> b;
	
	long long l = b-a+1;
	long long odd = 0, even = 0;
	if(a%2 == 1) {
		even = l / 2;
	} else {
		even = (l + 1) / 2;
	}
	
	odd = l - even;
	if(even % 2 == 1) l--;
	if(odd % 2 == 1) l--;
	
	cout << l << "\n";
	
	return 0;
}
