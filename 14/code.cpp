#include <iostream>
#include <vector>

int smallest(std::vector<int> arr, int &index){
    int smallest = arr[0];
    index = 0;
    
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < arr[index]){
            smallest = arr[i];
            index = i;
        }
    }

    return smallest;
}

int main()
{
    std::string number;
    int index;

    std::cout << "Type the amount of numbers: ";
    int size;
    std::cin >> size;

    std::vector<int> arr;

    for(int i = 0; i < size; i++){
        int digit;
        std::cin >> digit;
        arr.push_back(digit); 
    }

    for(int i = 0; i < size; i++){
        number += std::to_string(smallest(arr, index));
        arr.erase(arr.begin() + index);
    }

    for(int i = 1; i < number.length(); i++){
        if(number[0] == '0'){
            if(number[0 + i] != '0'){
                char temp = number[0];
                number[0] = number[0 + i];
                number[0 + i] = temp;
            }
        }
    }

    std::cout << number;

    return 0;
}