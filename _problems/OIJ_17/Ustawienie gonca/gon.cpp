#include <iostream>
#include <unordered_map>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;
	unordered_map<int, vector<pair<int, int>>> d1, d2;
	map<pair<int, int>, int> points;
	
	for(int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		d1[b+a].push_back({a, b});
		d2[b-a].push_back({a, b});
		points[{a, b}] = b-a;
	}
	cout << "\n";
	int max_size_d1 = 0, max_size_d2 = 0, msize_amt_d2 = 0;
	pair<int, int> ready_point;
	bool fnd = false;
	
	for(auto d : d2) {
		max_size_d2 = max(max_size_d2, (int)d.second.size());
	}
	
	for(auto d : d1) {
		max_size_d1 = max(max_size_d1, (int)d.second.size());
	}
	
	for(auto d : d2) {
		if((int)d.second.size() == max_size_d2) msize_amt_d2++;
	}
	
	for(auto d : d1) {
		if((int)d.second.size() != max_size_d1) continue;
		
		int cnt = 0;
		for(auto point : d.second) {
			int d2_size = d2[points[point]].size();
			if(d2_size == max_size_d2)
				cnt++;
		}
		
		if(msize_amt_d2 > cnt) {
			fnd = true;
			
			for(auto x : d2) {
				if((int)x.second.size() != max_size_d2)
					continue;
				int col = (d.first + x.first) / 2;
				int row = col - x.first;
				
				if(points.find({row, col}) == points.end()) {
					ready_point = {row, col};
					break;
				}
			}
			
			break;
		}
	}
	
	if(fnd) {
		cout << max_size_d1 + max_size_d2 << "\n";
		cout << ready_point.first << " " << ready_point.second << "\n";
	} else {
		
	}

	
	
	
	return 0;
}
