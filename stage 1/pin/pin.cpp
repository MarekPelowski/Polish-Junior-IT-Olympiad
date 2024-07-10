#include "bits/stdc++.h"

using namespace std;

void makeList(long long board_len, vector<long long> &pins, long long max, long long min) {
        for(int i = 0; i < 3; i++) {
            if(board_len % 3 == 0) {
                max = board_len * ((i + 1) / (double)3);
                min = (i / (double)3) * board_len;

                pins.push_back(max);
                pins.push_back(min);

                // cout << "max: " << max << endl;
                // cout << "min: " << min << endl << endl;

                makeList(board_len / 3, pins, max, min);


            } else return;
        }
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<long long> K(Q);
    for(int i = 0; i < Q; i++) {
        std::cin >> K[i];
    }

    long long board_len = pow(3, N);
    vector<long long> pins;

    long long max = board_len;
    long long min = 0;

    makeList(board_len, pins, max, min);

    sort(pins.begin(), pins.end());

    for(int i = 0; i < pins.size(); i++) {
        cout << pins[i] << endl;
    }

    return 0;
}