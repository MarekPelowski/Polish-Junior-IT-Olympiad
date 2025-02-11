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

        for(auto [key, numbers] : divisors_snapshot){
            long long candidate = d * key;

            if(T % candidate == 0) {
                if(divisors[candidate].empty() or divisors[candidate].size() > divisors[key].size() + 1) {
                    vector<long long> new_divisors = divisors[key];
                    new_divisors.push_back(d);
                    divisors[candidate] = new_divisors;
                }
            }
        }
    }

    if(divisors[T].empty())
        cout << "NIE";
    else {
        cout << divisors[T].size() << endl;;
        for(auto d : divisors[T])
            cout << d << " ";
    }


}