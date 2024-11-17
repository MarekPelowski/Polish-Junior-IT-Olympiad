#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main()
{
	int N;
	std::cin >> N;
	std::unordered_map<int, std::vector<int>> flavors;
	
	for(int i = 0; i < N; i++){
		int flavor;
		std::cin >> flavor;
		flavors[flavor].push_back(i);
	}
	
	int smLen = N + 1; // smallest lollipop piece
	
	for(const auto& flavor : flavors){
		if(flavor.second.size() >= 3){
			for(std::size_t i = 0; i < flavor.second.size() - 2; i++){
				smLen = std::min(smLen, flavor.second[i + 2] - flavor.second[i] + 1);
			}
		}
	}
	
	if(smLen == N + 1)
		std::cout << "NIE";
	else
		std::cout << smLen;
	
	return 0;
}
