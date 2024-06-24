#include "bits/stdc++.h"

using namespace std;

int main()
{
    long long X, Y;
    cin >> X >> Y;

    long long A, B;

    B = (Y - (X * 2)) / 2;
    A = X - B;

    cout << A << " " << B;

    return 0;
}