#include<bits/stdc++.h>
using namespace std;

#define print(a) for(auto x : a) cout << x << " "; cout << endl 

int maximumScore(int a, int b, int c) {
    vector<int> deck {a,b,c};
    vector<int> i {0,1,2};    
    int score=0, zeros=0;
    while (zeros!=2){
        sort(i.begin(), i.end(), [&](int k, int l){return deck[k]>deck[l];});
        // cout << "deck: ";
        // print(deck);
        // cout << "i: ";
        // print(i);
        if (deck[i.back()]==0){
            deck.erase(deck.begin()+i.back());
            i = {0,1};
            zeros++;
        } 
        else {
            deck[i.front()]--;
            deck[i.back()]--;
            score++;
        }
    }
    return score;
}

int main(void){
    cout << maximumScore(1,3,2);
}