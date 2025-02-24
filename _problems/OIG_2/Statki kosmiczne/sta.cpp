#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(int &vec_size, long long &maxNum, int &fuel, vector<long long> &vec) {
	cin >> vec_size;
	for(int i = 0; i < vec_size; i++) {
		long long a;
		cin >> a;
		vec.push_back(a * fuel);
		maxNum = max(maxNum, vec[i]);
	}
}

int bs(long long sum, vector<long long> &v) {
	int L = 0, R = v.size() - 1;
	
	while(L < R) {
		int mid = (L + R) / 2;
		
		if(v[mid] < sum) {
			L = mid + 1;
		} else {
			R = mid;
		}
	}
	
	if(v[L] < sum)
		return -1;
		
	return L;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	vector<long long> x, y, z;
	long long maxX = 0, maxY = 0, maxZ = 0;
	int sizeX, sizeY, sizeZ;
	
	input(sizeX, maxX, a, x);
	input(sizeY, maxY, b, y);
	input(sizeZ, maxZ, c, z);
	
	sort(z.begin(), z.end());
	
	long long minSum = (maxX + maxY + maxZ) / 2 + 1;
	int ans = 0;
	
	for(int i = 0; i < sizeX; i++) {
		for(int j = 0; j < sizeY; j++) {
			long long sum = x[i] + y[j];
			int pos = bs(minSum - sum, z);
			if(pos != -1) {
				ans += sizeZ - pos;
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
