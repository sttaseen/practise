#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    int bull=0, cow=0;
    char num1, num2;
    unordered_map<char, int> countGuess;
    unordered_map<char, int> countSecret;
    for(int i=0; i<secret.length(); i++){
        if (secret[i]==guess[i]){
            bull++;
        } else {
            num1 = guess[i];
            num2 = secret[i];
            countGuess[num1]++;
            countSecret[num2]++;
        }
    }
    for (char i='0'; i<='9'; i++){
        cow += (countGuess[i]<countSecret[i])?countGuess[i]:countSecret[i];
    }
    string answer = to_string(bull) + "A" + to_string(cow) + "B";
    return answer;
}

int main(void){
    cout << getHint("1123", "0111");
}