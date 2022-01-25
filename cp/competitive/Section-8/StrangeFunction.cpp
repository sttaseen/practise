#include <bits/stdc++.h>

using namespace std;

int F(int A){
    if (A/10==0) return A;
    int sum = 0;
    while(A!=0){
        sum+=A%10;
        A/=10;
    }
    return F(sum);
}

int solve(long long A, long long N){
    long long sum=1, divisor=100;
    while(N){
        if (N&1) sum*=A, sum%=divisor;
        A*=A;
        N/=2;
    }
    return sum;
}


int main(void){
    cout << solve(2,7);
}