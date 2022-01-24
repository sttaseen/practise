#include <bits/stdc++.h>

#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)

using namespace std;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

string bigAdd(string n1, string n2){
    string result = "";
    int i=0, carry=0, sum=0;

    if(n1.length()>n2.length()){
        swap(n1,n2);
    }

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());

    while (i<n2.length()||carry==1){
        if (i<n1.length()){   
            sum = (int)n1[i]+(int)n2[i]-96+carry;
        } else if (i<n2.length()){
            sum = (int)n2[i]-48+carry;
        } else {
            sum = carry;
        }
        result += to_string(sum%10);
        carry = sum/10;
        i++;
    }
    reverse(result.begin(), result.end());
    return result;
}

string bigMultiply(string n1, string n2){
    string result = "";

    if (n1.length()>n2.length()) swap(n1,n2);

    reverse(n2.begin(), n2.end());

    int m = stoi(n1), carry=0, multiple=0, i=0;
    
    while(carry!=0||i<n2.length()){
        
        if (i<n2.length()){
            multiple=m*(n2[i]-'0')+carry;
        } else {
            multiple = carry;
        }
        carry = multiple/10;
        result.push_back(multiple%10+'0');
        i++;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> bigMultiplyFactorial(int n1, vector<int> n2, int &size){
    vector<int> result(1000,0);

    int carry=0, multiple=0, i=0;
    
    while(i<size){         
        multiple=n1*n2[i]+carry;
        carry = multiple/10;
        result[i] = multiple%10;
        i++;        
    }

    while(carry){
        result[size] = carry%10;
        carry = carry/10;
        size += 1;
    }    
    return result;
}

void printReverse(vector<int> x, int size){
    for(int i=size-1; i>=0; i--){
        cout<<x[i];
    }
}

vector<int> bigFactorial(int n){
    vector<int> result(1000);
    int size = 1;
    result[0]=1;
    for(int i=2; i<=n; i++){
        result = bigMultiplyFactorial(i, result, size);
    }
    printReverse(result, size);
    return result;
}



int main(void){
    vector <int> n2 {1,2,3};
    int size = 3;
    vector<int> result = bigFactorial(100);
}