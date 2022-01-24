#include<bits/stdc++.h>
using namespace std;

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

long int pow(int m, int n){
    long int result = 1;
    while(n){
        if (n&1) result=result*m;        
        m=m*m;
        n=n>>1;
    }
    return result;
}

// this solution is appearently wrong?

string solve(int A,int B, int C){
    long int x = pow(A,C), y = pow(B,C);
    if (x>y) return ">";
    if (x<y) return "<";
    if (x==y) return "=";
}

int main(void){
    cout << solve(7,-3,4);
}


