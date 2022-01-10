#include<bits/stdc++.h>
using namespace std;

#define print(a)       for(auto x : a) cout << x << " "; cout << endl

int tippingPoint(vector<int> arr, int x, int l, int r){
    int mid = (l+r)/2;
    if(arr[l] >= x){
        return l;
    }
    if(arr[r] < x){
        return r;
    }
    if(arr[mid]<=x && arr[mid+1]>x){
        return mid;
    }
    
    if(arr[mid]<x){
        return tippingPoint(arr, x, mid+1, r);
    } else {
        return tippingPoint(arr, x, l, mid-1);
    }
}

vector<int> findClosestElements(vector<int> arr, int k, int x) {
    int tip = tippingPoint(arr, x, 0, arr.size()-1), count=0, l=tip, r=tip+1;
    vector<int> results(k);
    while (count<k && l>=0 && r<=arr.size()-1){
        if (arr[l] == x){            
            results[count++] = x;
            l--;
        }
        if (x-arr[l]<=arr[r]-x){
            results[count++] = arr[l--];
        } else {
            results[count++] = arr[r++];
        }
    }

    while(count<k && l>=0){
        results[count++] = arr[l--];
    }
    
    while(count<k && r<=arr.size()-1){
        results[count++] = arr[r++];
    }            
        
    sort(results.begin(), results.end());
    return results;
}

int main(void){
    vector<int> arr {-663,-580,-547,-497,-495,-373,-292,-276};
    vector<int> result = findClosestElements(arr, 5, -500);
    print(result);
}