#include <iostream>
#include <vector>

using namespace std;

int shortestPath(long long a, long long b) {
    if(a < b)
        swap(a, b);
    if(a == b)
        return 0;
    else
        return shortestPath(a / 2, b) + 1;
}

int main() {
    int Q;
    cin >> Q;
    vector <pair <long long, long long>> nodes(Q);
    for(int i = 0; i < Q; i++)
        cin >> nodes[i].first >> nodes[i].second;

    for(const auto& x : nodes)
        cout << shortestPath(x.first, x.second) << "\n";

    return 0;
}