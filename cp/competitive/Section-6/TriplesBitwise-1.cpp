#include<bits/stdc++.h>
using namespace std;

//There is a map approach but this worked for the sample so hey! if it works, it works.

int countTriplets(vector<int> nums) {
    int count = 0;
    int n = nums.size();
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            for (int k=0; k<n; k++){
                if ((nums[i]&nums[j]&nums[k])==0){
                    count++;
                }
            }
        }
    }
    return count;
}

int main(void){
    vector<int> nums {2,1,3};
    cout << countTriplets(nums);
}