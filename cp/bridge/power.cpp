#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n = 4;
    int x = 2;
    int y = 1;
    while(n){
        if(n&1) y=y*x;
        x = x*x;
        n/=2;
    }
    cout << y;
}