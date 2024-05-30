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
    for(int i = 0; i < N; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
    int num;
    int amount = 1;
    std::vector<int> nums;

    for(int i = 0; i < N; i++) {
        if(T % A[i] == 0) {
            num = A[i];
            nums.erase(nums.begin(), nums.end());
            nums.push_back(num);
            for(int j = i + 1; j < N; j++) {
                if(num * A[j] <= T) {
                    num *= A[j];
                    amount++;
                    nums.push_back(A[j]);
                }

                if(num == T){
                    std::cout << i << " " << amount << " nums: ";
                    for(int k = 0; k < nums.size(); k++) {
                        std::cout << nums[k] << " ";
                    }
                    std::cout << std::endl << std::endl;
                    nums.erase(nums.begin(), nums.end());
                    num = A[i];
                    nums.push_back(num);
                    amount = 1;
                }
            }
        }
    }

    return 0;
}