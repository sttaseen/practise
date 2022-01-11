#include<bits/stdc++.h>
using namespace std;

int distributeCandies(vector<int> candies) {
    int n, t;
    set<int> types;
    for (int i=0; i<candies.size(); i++){
       types.insert(candies[i]);
    }
    n = candies.size()/2;
    t = types.size();
    return (t<n)?t:n;
}

int main(void){
    vector<int> candies {1,1,2,3,2,2};
    cout << distributeCandies(candies);
}