#include <bits/stdc++.h>

using namespace std;

int uniqueOne(vector<int> arr){
    int result = 0;
    for (int i=0; i<arr.size(); i++){
        result = result ^ arr[i];
    }
    return result;
}

void uniqueTwo(vector<int> arr){
    int result = 0, a = 0, b = 0;

    for (int i=0; i<arr.size(); i++){
        result = result ^ arr[i];
    }

    int pos = 0, temp = result;
    while ((temp&1)==0){
        pos ++;
        temp = temp>>1;
    }
    
    for (int i=0; i<arr.size(); i++){
        if ((arr[i]>>pos)&1){
            a = a ^ arr[i];
        }
    }
    b = result^a;

    cout << "a = " << a <<endl;
    cout << "b = " << b <<endl;
}

int uniqueThree(vector <int> arr){
    vector<int> bits(32,0);
    int value = 0;

    for (int pos=0; pos<32; pos++){
        for (int i=0; i<arr.size(); i++){
            bits[pos] = (arr[i]>>pos)&1;
        }
        bits[pos] %= 3;
    }
    for (int pos=0; pos<32; pos++){
        value += (1<<pos)*bits[pos];
    }
    return value;
}

int main(void){
    cout << (4^9)<< endl;
    vector<int> arr {1,1,1,2,2,2,3};
    cout << uniqueThree(arr);
}