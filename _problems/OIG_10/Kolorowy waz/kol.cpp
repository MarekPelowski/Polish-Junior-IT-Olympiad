#include <iostream>
#include <string>
#include <vector>

#define ll long long
using namespace std;

const int mxA = 510;
const int mxN = 5e5+10;
int a, b, n, m;
int x = 0, y = 0;
vector<vector<int>> p(mxA, vector<int>(mxA));
vector<int> ans(mxN);

void update(int t) {
	if(p[y][x] <= m && p[y][x]-1 <= n-t) ans[t+p[y][x]-1]++;
}

int direct_y(int y, char move) {
	if(move == 'N') return y-1;
	else if(move == 'S') return y+1;
	else return y;
}

int direct_x(int x, char move) {
	if(move == 'W') return x-1;
	else if(move == 'E') return x+1;
	else return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> a >> b;
	for(int i = 0; i < a; i++) {
		for(int j = 0; j < b; j++) {
			cin >> p[i][j];
		}
	}
	cin >> n >> m;
	string moves;
	cin >> moves;
	update(0);
	
	for(int i = 1; i <= n; i++) {
		char m = moves[i-1];
		x = direct_x(x, m);
		y = direct_y(y, m);
		update(i);
	}
	
	for(int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}
