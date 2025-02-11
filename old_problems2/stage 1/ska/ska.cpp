#include "bits/stdc++.h"

using namespace std;

int main()
{
    string socks;
    cin >> socks;

    int B = 0, C = 0;

    for(char sock : socks) {
        if(sock == 'B') B++;
        else C++;
    }

    int result = B / 2 + C / 2;
    cout << result;

    return 0;
}