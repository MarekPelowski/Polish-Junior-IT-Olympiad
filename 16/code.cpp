#include <iostream>
#include <vector>

int findSumQuadrilaterals(std::vector<int> &list);

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> list;

    for(int i = 0; i < N; i++){
        int num;
        std::cin >> num;
        list.push_back(num);
    }

    std::cout << findSumQuadrilaterals(list);

    return 0;
}

int findSumQuadrilaterals(std::vector<int> &list){
    int n = list.size();
    int sum = 0;

    for(int i = 0; i < n - 3; i++){
        int addition = list[i] + list[i + 1] + list[i + 2] + list[i + 3];

        if(list[i] + list[i + 1] == list[i + 2] + list[i + 3]){
            sum += addition;
        }
        else if(list[i] + list[i + 2] == list[i + 1] + list[i + 3]){
            sum += addition;
        }
        else if(list[i] + list[i + 3] == list[i + 1] + list[i + 2]){
            sum += addition;
        }
    }

    return sum;
}