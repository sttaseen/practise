#include <iostream>
#include <unordered_map>

// this code finds takes an integer n as input and return the n-th term of the
// fibonacci sequence.

// memoisation is used to make the recursion faster
std::unordered_map <int, unsigned long> memo;

unsigned long fib(int n){
    if (memo.find(n)!=memo.end()){
        return memo[n];
    }
    if (n<=2){
        memo.insert(std::pair<int, unsigned long>(n, 1));
        return 1;
    } else {
        memo.insert(std::pair<int, unsigned long>(n, fib(n-1)+fib(n-2)));
        return memo[n];
    }
}

// test cases
int main(void){
    std::cout << fib(2) << std::endl; //1
    std::cout << fib(1) << std::endl; //1
    std::cout << fib(5) << std::endl; //5
    std::cout << fib(6) << std::endl; //8
    std::cout << fib(300) << std::endl; //17658870469870104080
}