#include <iostream>

using namespace std;

int hammingDistance(int x, int y) {
    int cnt=0;
    int mask = 1;
    for (int i=0; i<31; i++){
        if((x&mask)^(y&mask)){
            cnt++;
        }
        mask = mask<<1;
    }
    return cnt;
}

int main(void){
    cout << hammingDistance(1,4);
}