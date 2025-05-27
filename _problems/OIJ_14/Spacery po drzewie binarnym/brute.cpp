#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    while(q--) {
        long long a, b;
        cin >> a >> b;

        int cnt = 0;
        while(a != b) {
            cnt++;
            if(a < b) {
                swap(a, b);
            }
            a /= 2;
        }

        cout << cnt << "\n";
    }

    return 0;
}