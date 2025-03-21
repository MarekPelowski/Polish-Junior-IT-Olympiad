#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> tree;
int L, R;

void dfs(int a) {
	if(L <= a && a <= R) {
		cout << a << " ";
		return;
	}
	
	dfs(2*a);
	dfs(2*a+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	
	L = (1 << (n-1));
	R = (1 << n) - 1;
	tree.resize(R+1);
	
	for(int i = 1; i <= R; i++) {
		int a, b;
		cin >> a >> b;
		tree[i] = a+b;
	}
	
	dfs(1);
	
	
	return 0;
}
