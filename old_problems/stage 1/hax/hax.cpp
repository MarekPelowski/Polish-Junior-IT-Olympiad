#include "bits/stdc++.h"

using namespace std;

int main()
{
    string text;
    cin >> text;
    string text_hacked = text;
    for(int i = 0; i < text.length(); i++){
        if(text[i] == 'a') text_hacked[i] = '4';
        if(text[i] == 'e') text_hacked[i] = '3';
        if(text[i] == 'i') text_hacked[i] = '1';
        if(text[i] == 'o') text_hacked[i] = '0';
        if(text[i] == 's') text_hacked[i] = '5';
    }
    cout << text_hacked;

    return 0;
}