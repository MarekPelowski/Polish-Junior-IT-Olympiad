#include <iostream>

std::string solve(int n)
{
    int amtZ = n / 26;
    char lstLetter = 96 + n % 26; // ASCII code
    std::string txtZ;

    for(int i = 0; i < amtZ; i++)
        txtZ += "z";

    return txtZ + lstLetter;
}

int main()
{
    int n;
    std::cin >> n;

    std::cout << solve(n);

    return 0;
}