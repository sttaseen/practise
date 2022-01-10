#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
#define print(a) for(auto x : a) cout << x << " "; cout << endl

int solve(vector<int> nums){
    int sum=0, adder;
    while(nums.size()!=1){   
        sort(nums.begin(), nums.end());
        adder = nums[0] + nums[1];
        sum+=adder;
        nums.erase(nums.begin(), nums.begin()+2);
        nums.push_back(adder);
    }
    return sum;
}

int main(void){
    vector<int> nums = {1,2,3,4,5};
    cout << solve(nums);
}



