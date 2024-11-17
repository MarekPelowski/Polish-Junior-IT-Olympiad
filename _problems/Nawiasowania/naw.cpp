#include <iostream>
#include <cmath>
#include <string>

int main()
{
	int N;
	std::cin >> N;

	// 1 + 2 + 3 + 4 + ... + n = (n * (n + 1)) / 2
	// delta = b^2 - 4ac

	int rmBr = N; // remaining brackets  

	std::string ans;

	while(rmBr > 0){
		long long delta = 1 - 4 * (-2 * (long long)rmBr); 
		int x = (-1 + (int)std::sqrt(delta)) / 2;
		
		rmBr -= (x * (x + 1) / 2);
		
		for(int i = 0; i < x; i++){
			ans += "()";
		}
		
		ans.push_back(')');
	}
	
	std::cout << ans;

	return 0;
}
