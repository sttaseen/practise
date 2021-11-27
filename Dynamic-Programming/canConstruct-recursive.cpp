#include <iostream>
#include <string>
#include <unordered_map>

// canConstruct takes input a string, an array of strings and the length of the array
// it returns if the strings in the array can be used to make up the target string

std::unordered_map <std::string, bool> memo;

bool canConstruct(std::string target, std::string wordBank[], int length){
    std::string buffer, key;
    
    key = target + ";";
    for (int i = 0; i< length; ++i){
        key += wordBank[i] + ",";
    }

    if (memo.find(key)!=memo.end()){
        return memo[key];
    }

    if (target == ""){
        memo[key] = true;
        return true;
    }

    for (int i = 0; i< length; ++i){
        size_t pos = target.find(wordBank[i]);
        if(pos != std::string::npos){
            buffer = target;
            target.erase(pos, wordBank[i].length());
            if (canConstruct(target, wordBank, length)==true){
                memo[key] = true;
                return true;
            }
            target = buffer;
        }
    }
    memo[key] = false;
    return false;
}

int main(void){
    std::string test[5] = {"ab", "abc", "cd", "def", "abcd"};
    std::cout << canConstruct("abcdef", test, 4);
}