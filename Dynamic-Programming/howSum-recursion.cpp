#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

// howSum takes input: a number, an array of numbers and the length of that array
// it returns what elements in the array need to be summed to make the target number


std::unordered_map <std::string, std::vector<int> > memo;

std::vector<int> howSum(int targetSum, int* numbers, int length){
    std::vector<int> v;

    std::string key = std::to_string(targetSum) + ";";
    for (int i=0; i<length; ++i){
        key += std::to_string(numbers[i]) + ",";
    }

    if (memo.find(key)!= memo.end()){
        return memo[key];
    }

    if (targetSum==0){
        memo[key] = v;
        return v;
    }
    if (targetSum<0){
        v.push_back(-1);
        memo[key] = v;
        return v;
    }

    for (int i=0; i<length; ++i){
        int remainder  = targetSum-numbers[i];
        std::vector<int> remainderResult = howSum(remainder, numbers, length);

        if (remainderResult.empty()){
            remainderResult.push_back(numbers[i]);
            memo[key] = remainderResult;
            return remainderResult;
        } else if (remainderResult[0]!=-1){
            remainderResult.push_back(numbers[i]);
            memo[key] = remainderResult;
            return remainderResult;
        }
    }
    v.push_back(-1);
    memo[key] = v;
    return v;
}

int main(void){
    int test[] = {3,5,1};
    std::vector<int> results = howSum(20, test, 2);

    for(int i=0; i<results.size(); ++i){
        std::cout << results[i] << ", " ;
    }
    
}