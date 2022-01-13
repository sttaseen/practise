#include<bits/stdc++.h>
using namespace std;

int HammingDistance(int a, int b){
    int mask=1, count=0, c=a^b;
    for(int i=0; i<32; i++){
        if(c&mask) count++;
        mask = mask<<1;
    }
    // cout << "a: " << a << " b: " <<  b << " val: " <<count <<endl;
    return count;
}

int totalHammingDistance(vector<int> nums) {
    int sum=0, n=nums.size();
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n;j++){
            sum += HammingDistance(nums[i], nums[j]);
        }
    }
    return sum;
}

int main(void){
    vector<int> nums {4,14,2};
    cout << totalHammingDistance(nums);
}