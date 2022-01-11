#include<bits/stdc++.h>
using namespace std;



bool isPowerOfFour(int n) {
    if (n<=0){
        return false;
    } else if (n==1){
        return true;
    }
    return isPowerOfFour(n>>2);
}