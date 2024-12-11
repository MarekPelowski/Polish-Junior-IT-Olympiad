#include <algorithm>
#include <iostream>

using namespace std;

int findSum(long long n) {
    if(n == 0)
        return 0;
    return findSum(n / 10) + n % 10;
}

int main() {
    long long A, B;
    cin >> A >> B;
    long long n = A, dg = 1; // dg -> digit growth
    int sum = findSum(n) - 1, maxSum = 0;
    long long lastN = n - 1;

    while(n <= B) {
        if(n > lastN) {
            sum++;
            if(sum > maxSum)
                maxSum = sum;
        }
        lastN = n;
        if(n / dg % 10 == 9)
            dg *= 10;
        else
            n += dg;
        if(dg > n) {
            n = dg;
            dg = 1;
            sum = 0;
        }
    }

    cout << maxSum << "\n";

    return 0;
}