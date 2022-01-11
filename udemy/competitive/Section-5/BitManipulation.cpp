#include <iostream>

using namespace std;

int getIthBit(int n, int i){
    return (n&1<<i)>>i;
}

void clearIthBit(int &n, int i){
    int mask = ~(1<<i);
    n = mask&n;
}

void setIthBit(int &n, int i, int v){
    n = ~(1<<i)&n;
    int mask = v<<i;
    n = mask|n;
}

void clearLastIBits(int&n, int i){
    int mask = -1 << i;
    n = mask&n;
}

void clearBitsInRange(int &n, int i, int j){
    int maskA = -1<<(j+1);
    int maskB = (1<<i)-1;
    int maskC = maskA|maskB;
    n = maskC&n;
}

void setBits(int &N, int M, int i, int j){
    clearBitsInRange(N, i, j);
    int mask = M<<i;
    N = N|mask;
}


int powerOfTwo(int n){
    int mask = n-1;
    return ((mask&n)==0)?1:0;
}
int main(void){
    int n = 8;
    cout << powerOfTwo(16);

}