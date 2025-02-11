#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

int main()
{
	std::string digitsStr;
	int K;
	std::cin >> digitsStr;
	std::cin >> K;
	std::vector<int> digits;
	
	for(const auto& digit : digitsStr)
		digits.push_back(digit - '0');
	std::sort(digits.begin(), digits.end());
	
	int minNumLen = digits.size() / K;
	int maxNumAmount = digits.size() % K;
	int maxNumLen;
	
	if(maxNumAmount == 0)
		maxNumLen = minNumLen;
	else
		maxNumLen = minNumLen + 1;

	auto zerosAmountIterator = std::lower_bound(digits.begin(), digits.end(), 1);
	int zerosAmount = zerosAmountIterator - digits.begin();
	
	for(int i = 0; i < K; i++){
		std::swap(digits[i], digits[i + zerosAmount]);
	}
	
	long long sum = 0;
	
	for(int i = 1; i <= maxNumLen; i++){
		for(int j = 0; j < maxNumAmount; j++){
			int index = (i - 1) * K + j;
			long long power = std::pow(10, maxNumLen - i);
			sum += digits[index] * power;
		}
		if(i <= minNumLen){
			for(int j = 0; j < K - maxNumAmount; j++){
				int index = (i - 1) * K + j + maxNumAmount;
				long long power = std::pow(10, minNumLen - i);
				sum += digits[index] * power;
			}
		}
	}
	
	std::cout << sum;

	return 0;
}
