#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int findIndex(vector <int> vec, int num) {
    // int left = 0, right = vec.size() - 1;

    // while(left < right) {
    //     int mid = (left + right) / 2;
    //     if(vec[mid] < num)
    //         left = mid + 1;
    //     else
    //         right = mid;
    // }

    // if(vec[left] >= num)
    //     return left;
    // else
    //     return -1;
    
    auto it = lower_bound(vec.begin(), vec.end(), num);
    if (it == vec.end()) return -1;
    return it - vec.begin();

}

int main() {
    ios_base::sync_with_stdio(0);

    int N, Q;
    cin >> N;
    vector <int> A(N);
    for(int i = 0; i < N; i++)
        cin >> A[i];

    cin >> Q;
    vector <int> K(Q);
    for(int i = 0; i < Q; i++)
        cin >> K[i];

    int streak = 1;
    vector <int> streaks;
    for(int i = 1; i < N; i++) {
        if(A[i] > A[i-1])
            streak++;
        else {
            streaks.push_back(streak);
            streak = 1;
        }
    }
    streaks.push_back(streak);
    sort(streaks.begin(), streaks.end());

    int sum = 0;
    int strS = streaks.size();
    vector <pair <int, int>> sums(strS, {0, 0});
    for(int i = strS - 1; i >= 0; i--) {
        sum += streaks[i];
        sums[i].first = sum;
        sums[i].second = strS - i;
    }

    for(int num : K) {
        int index = findIndex(streaks, num);
        if(index == -1) {
            cout << 0 << "\n";
            continue;
        }
        cout << sums[index].first - (num - 1) * sums[index].second << "\n";
    }

    return 0;
}