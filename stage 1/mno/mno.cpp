#include "bits/stdc++.h"

using namespace std;

int main()
{
    int N;
    long long T;
    cin >> N >> T;
    vector<long long> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    map<long long, vector<long long>> divisors;
    divisors[1] = {};


    for(auto d : A) {
        auto divisors_snapshot = divisors;
        for(auto [key, nums] : divisors_snapshot) {
            if(T % (d * key) == 0) {
                if(divisors.find(d * key) == divisors.end() or divisors[d * key].size() > nums.size()) {
                    divisors[d * key] = nums;
                    divisors[d * key].push_back(d);
                }
            }
        }
    }

    if(divisors[T].empty())
        cout << "NIE";
    else {
        cout << divisors[T].size() << endl;
        for(long long d : divisors[T]) {
            cout << d << " ";
        }
    }
}