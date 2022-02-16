#include<bits/stdc++.h>
#define int long long int
using namespace std;



int pow(int m, int n){
    int result = 1;
    while(n){
        if (n&1) result=result*m;        
        m=m*m;
        n=n>>1;
    }
    return result;
}

const int mod = 1e9+7;

int modPow(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res*=a, res%=mod;
        a*=a, a%=mod;
        b/=2;
    }
    return res;
}

int32_t main(void){
    cout << modPow(2,200);
}