#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int N, A, B;
	cin >> N >> A >> B;
	vector<pair<double, int>> X(N+1);
	X[0].first = A;
	X[0].second = 0;
	
	for(int i = 1; i <= N; i++) {
		cin >> X[i].first >> X[i].second;
		if(X[i].second > A) X[i].second = -X[i].second;
	}
	sort(X.begin(), X.end());
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	int neseser = A;
	
	for(int i = 0; i < N; i++) {
		double time = (X[i+1].first - X[i].first) / (X[i].second - X[i+1].second);
		if(time > 0)
			pq.push({time, i});
	}
	
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq_copy = pq;
	
	cout << "\n";
	while(!pq_copy.empty()) {
		int i = pq_copy.top().second;
		cout << pq_copy.top().first << ": " << X[i].second << " " << X[i+1].second << "\n";
		pq_copy.pop();
	}
	cout << "\n";
	
	while(!pq.empty()) {
		double time = pq.top().first, i = pq.top().second;
		int X1 = X[i].first;
		int V1 = X[i].second;
		
		int new_pos = X1 + V1 * time;
		
		
		cout << X[i].second << " " << X[i+1].second << " " << new_pos << "\n";
		
		pq.pop();
	}
	
	return 0;
}
