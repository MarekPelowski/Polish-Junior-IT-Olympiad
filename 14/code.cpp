#include <iostream>
#include <vector>

int k = 0;

std::string smallest(std::vector<int> arr){
    for(int m = 0; m < arr.size(); m++){
        std::cout << arr[m] << std::endl;
    }

    int smallest = arr[0];
    k = 0;
    
    for(int i = 1; i < arr.size(); i++){
        if(arr[i] < arr[k]){
            smallest = arr[i];
            k = i;
        }
    }

    return std::to_string(smallest);
}

int main()
{
    std::string number;

    std::cout << "Type the amount of numbers: ";
    int size;
    std::cin >> size;

    std::vector<int> arr;

    for(int i = 0; i < size; i++){
        int size2;
        std::cin >> size2;
        arr.push_back(size2); 
    }

    for(int i = 0; i < size; i++){
        number += smallest(arr);
        arr.erase(arr.begin() + k);
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