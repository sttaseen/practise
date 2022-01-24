#include <bits/stdc++.h>

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


string solve(int A, int B, int C){
    int sign1= !((A<0)&&(C%2));
    int sign2= !((B<0)&&(C%2));

    // bug(sign1, sign2);

    if (sign1==sign2){
        if(abs(A)>abs(B)) return ">";
        if(abs(A)<abs(B)) return "<";
        if(abs(A)==abs(B)) return "=";
    } else {
        if (sign1) return ">";
        if (sign2) return "<";
    }
}

int main(void){
    cout << solve(7,7,3);
}

