#include<bits/stdc++.h>
using namespace std;

#define print(a)       for(auto x : a) cout << x << " "; cout << endl

int tippingPoint(vector<int> arr, int x, int l, int r){
    int mid = (l+r)/2;
    cout << "Mid: " << mid << endl;
    if(arr[l] >= x)
        cout << "here1";
        return l;
    if(arr[r] < x)
        cout << "here2";
        return r;
    if(arr[mid]<=x && arr[mid+1]>x)
        cout << "here3";
        return mid;
    
    if(arr[mid]<x){
        cout << "here4";
        return tippingPoint(arr, x, mid+1, r);
    } else {
        cout << "here5";
        return tippingPoint(arr, x, l, mid-1);
    }
}

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    int tip = tippingPoint(arr, x, 0, arr.size()), count=0;
    cout <<"tip: " <<  tip <<endl;
    vector<int> results;
    while (count<k){
        print(results);
        cout << "arr[tip]: " << arr[tip] << endl;
        cout << "arr[tip]-x: " << abs(arr[tip]-x) <<endl;
        cout << "x-arr[tip+1] " << abs(x-arr[tip+1]) <<endl;
        if(abs(arr[tip]-x)<=abs(x-arr[tip+1])){
            cout << "here1"<<endl;
            results.push_back(arr[tip]);
            arr.erase(arr.begin()+tip);
            count++;
        } else {
            results.push_back(arr[tip+1]);
            arr.erase(arr.begin()+tip+1);
            count++;
        }
    }
    sort(results.begin(), results.end());
    return results;

}

int main(void){
    vector<int> arr {2,4,6,7,8,9,11};
    int tip = tippingPoint(arr, 8, 0, arr.size());
    cout <<"tip: " <<  tip <<endl;
    // vector<int> result = findClosestElements(arr, 3, 8);
    // print(result);
}