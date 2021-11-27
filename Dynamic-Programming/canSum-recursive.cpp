#include <string>
#include <iostream>
#include <unordered_map>

// canSum inputs an integet, an array of integers andthe length of the array
// it returns a boolean stating if the numbers in the array can be summed up to make the targetSum

std::unordered_map <std::string, bool> memo;

bool canSum(int targetSum, int numbers[], int length){
    std::string key = std::to_string(targetSum) + ";";
    for (int i = 0; i< length; ++i){
        key += std::to_string(numbers[i]) + ",";
    }
    
    if(memo.find(key)!=memo.end()){
        return memo[key];
    }

    for(int i=0; i<length; ++i){
        int remainder =  targetSum - numbers[i];
        if(remainder ==0){
            memo[key] = true;
            return true;
        } else if (remainder>0){
            if(canSum(remainder, numbers, length)==true){
                return true;
            }
        }
    }
    return false;
}

int main(void){
    int test[] = {3,8};
    std::cout << canSum(100, test, 2) << std::endl;
}