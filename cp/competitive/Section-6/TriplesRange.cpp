#include<bits/stdc++.h>
using namespace std;

int rangeBitwiseAnd(int left, int right) {
    int ans = ~(0);
    for (int i=left; i<=right; i++){
        ans = ans & i;
    }
    return ans;
}

int main(void){
    cout << rangeBitwiseAnd(5,7);
}