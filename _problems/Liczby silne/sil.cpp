#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

long long fac(int a) {
  long long ans = 1;
  for(int i = 2; i <= a; i++)
    ans *= i;
  return ans;
}

vector<long long> getSums() {
  vector<unordered_set<long long>> sums(17);
  sums[1].insert(0);

  for(int i = 1; i <= 15; i++) {
    for(auto sum : sums[i]) {
      sums[i + 1].insert(sum);
      sums[i + 1].insert(sum + fac(i));
    }
  }

  vector<long long> result;
  for(auto s : sums[16])
    result.push_back(s);

  return result;
}

int getIndex(vector<long long> a, long long b) {
  int left = 0, right = a.size() - 1;
  while(left < right) {
    int mid = (left + right) / 2;
    if(a[mid] < b)
      left = mid + 1;
    else
      right = mid;
  }

  if(a[left] < b) return -1;
  return left;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int Q;
  cin >> Q;
  vector<long long> sums = getSums(), answers;
  sort(sums.begin(), sums.end());

  for(int i = 0; i < Q; i++) {
    long long a, b;
    cin >> a >> b;
    long long ans = 0;

    int index = getIndex(sums, a);
    if(index != -1) {
      for(int i = index; sums[i] <= b; i++){
        ans += sums[i];
      }
    }
    answers.push_back(ans);
  }

  for(long long ans : answers)
    cout << ans << "\n";

  return 0;
}