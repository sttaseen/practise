#include <bits/stdc++.h>

using namespace std;

const int mod = 10;

int mul(int a, int b){  
    int res=0;
    while(b){
        if(b&1)res+=a;
        a+=a, a%=mod;
        b=b>>1;
    }
    return res;
}


int main(void){
    cout << mul(24132,16);
}