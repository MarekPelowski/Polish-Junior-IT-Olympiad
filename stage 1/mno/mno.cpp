#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    long long T;
    std::cin >> N >> T;
    std::vector<long long> A(100);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin(), A.end());
    std::reverse(A.begin(), A.end());
    long long num = 1;
    std::vector<long long> nums;
    std::vector<long long> smallnums;

    for(int i = 0; i < N; i++) {
        if(T % A[i] == 0) {
            nums.erase(nums.begin(), nums.end());
            num = A[i];
            nums.push_back(num);
            for(int j = i; j < N; j++) {
                if(j + 1 < N) {
                    if(num * A[j + 1] <= T) {
                        num *= A[j + 1];
                        nums.push_back(A[j + 1]);
                    }
                }
                if(num == T){
                    if(smallnums.empty() or nums.size() < smallnums.size()) smallnums = nums;
                    num = A[i];
                    nums.erase(nums.begin(), nums.end());
                    nums.push_back(num);
                }
            }
        }
    }
    if(smallnums.empty()){
        std::cout << "NIE";
    }
    else {
        std::cout << smallnums.size() << std::endl;
        for(int i = 0; i < smallnums.size(); i++) {
            std::cout << smallnums[i] << " ";
        }
    }

    return 0;
}