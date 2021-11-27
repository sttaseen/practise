#include <iostream>

// this code takes an integer, n as an input and returns the n-th term of the
// fibonacci sequence.

// this version doesn't use an array to store the terms of the sequence
// instead, it tries to work out the i-th term by finding the previous 2 terms before i


unsigned long fib(int n){
    unsigned long value, last=1, buffer;
    for (int i = 1; i<=n; ++i){
        if (i<=2){
            value = 1;
        } else {
            buffer = last;
            last = value;
            value = value + buffer;
        }
    }
    return value;
}

int main(void){
    std::cout << fib(2) << std::endl; //1
    std::cout << fib(1) << std::endl; //1
    std::cout << fib(5) << std::endl; //5
    std::cout << fib(6) << std::endl; //8
    std::cout << fib(300) << std::endl; //17658870469870104080
}