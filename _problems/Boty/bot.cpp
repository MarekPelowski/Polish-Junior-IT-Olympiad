#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 200000;
int N, M;
vector<int> A(MAX_N+10);
vector<int> cur_place;
vector<int> parents_amnt(MAX_N+10);
vector<int> bots_places;

int DFS(int limit) {
	vector<bool> visited(MAX_N+10);
	vector<int> depth(MAX_N+10);
	vector<int> cur_place2 = cur_place;
	bots_places.clear();
	bool changes = true;
	int cnt = 0;
	
	while(changes) {
		changes = false;
		
		for(int i = 0; i < (int)cur_place2.size(); i++) {
			int child = A[cur_place2[i]];
			int parent = cur_place2[i];
		
			if(!visited[child]) {
				visited[child] = true;
				changes = true;
				cur_place2[i] = child;
				
				if(depth[parent] == limit) {
					bots_places.push_back(child);
					depth[child] = 0;
					cnt++;
				} else {
					depth[child] = depth[parent] + 1;	
				}
			}
		}
	}
	
	return cnt + (int)cur_place.size();
}

int find_ans() {
	int left = 0, right = MAX_N;
	
	while(left != right) {
		int mid = (left + right) / 2;
		
		if(DFS(mid) <= M) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	
	return left;
}

bool no_leaves(vector<bool> visited, int start, int x, bool ans) {
	if(!visited[x]) {
		visited[x] = true;
		if(parents_amnt[x] == 1 && ans) {
			return no_leaves(visited, start, A[x], true);
		} else {
			return no_leaves(visited, start, A[x], false);
		}
	}
	if(x == start && ans) {
		return true;
	} else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	cin >> M;
	
	for(int i = 1; i <= N; i++) {
		parents_amnt[A[i]]++;
	}
	
	for(int i = 1; i <= N; i++) {
		if(parents_amnt[i] == 0) {
			cur_place.push_back(i);
		}
	}
	
	vector<bool> visited(N+10);
	for(int i = 1; i <= N; i++) {
		if(!visited[i] && no_leaves(visited, i, i, true)) {
			cur_place.push_back(i);
		}
	}
	
	if((int)cur_place.size() > M) {
		cout << "NIE\n";
		return 0;
	}
	
	int ans = find_ans();
	int bots = DFS(ans);
	
	cout << ans << "\n" << bots << "\n";
	for(int i = 0; i < (int)cur_place.size(); i++) {
		cout << cur_place[i] << " ";
	}
	for(int i = 0; i < (int)bots_places.size(); i++) {
		cout << bots_places[i] << " ";
	}
	
	cout << "\n";
	
	return 0;
}

// this solution got only 0%