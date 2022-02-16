#include<bits/stdc++.h>
using namespace std;

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


const long long int mod = 1e9+7;


long long int modPow(long long int a, long long int b){
    long long int res = 1;
    while(b){
        if(b&1) res*=a, res%=mod;
        a*=a, a%=mod;
        b/=2;
    }
    return res;
}

int locker(int n){
    long long int res, twos, threes;
    if (n==1) return 1;

    if (n%3==0) threes = n/3, twos = 0;
    if (n%3==1) threes = n/3-1, twos = (n-3*threes)/2;
    if (n%3==2) twos = 1, threes = (n-1)/3;
    // bug(twos, threes);
    res = (modPow(2,twos)*modPow(3, threes))%mod;
    return res;
}


int32_t main(void){
    cout << locker(4);
}

