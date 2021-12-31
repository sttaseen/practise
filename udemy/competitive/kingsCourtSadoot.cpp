#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define print(a) for(auto x : a) cout << x << " "; cout << endl


bool disgraced(vector<char> line, int i){
    bool left = (line[i]-line[i-1]==1)&&!(i==0);
    bool right = (line[i]-line[i+1]==1)&&!(i==line.size()-1);
    return left||right;
}


int dismiss(vector<char> line, int S){
    int count=0, i=0;

    //vector V will store the index positions of the elements from highest to lowest
    //i.e. if line = [3,1,2], then V = [0,2,1]

    vector<int> V(S);
    iota(V.begin(),V.end(),0); //O(S)
    sort(V.begin(),V.end(), [&](int l,int m){return line[l]>line[m];}); //O(SlogS)

    //can delete this block out; just here to see how it works
    cout << endl;
    print(line);
    cout << "V: ";
    print(V);

    while (i<V.size()){ 
        if (disgraced(line, V[i])){
            line.erase(line.begin()+V[i]);
            V.erase(V.begin()+i); 

            //this code is disgusting and i hate myself for it. Please fix this part if you can.
            //I am creating a new V and sorting it everytime it is changed.
            //time complexity is O(S*(S+SlogS)) => O(S^2logS)
            //since, S < 100, this should be fine, I hope (｀◔ ω ◔´)
            
            iota(V.begin(),V.end(),0); //O(S)
            sort(V.begin(),V.end(), [&](int l,int m){return line[l]>line[m];}); //O(SlogS)
            count++; 
            //i =-1+1 = 0; i becomes 0 next loop
            i = -1;         
        }
        i++;

        //can also delete this block; just here to see how it works after each loop
        cout << endl;
        print(line);
        cout << "V: ";
        print(V);
        cout << endl;
    }

    return count; 
}

int main() {
    int S;
    string strInput;

    cin>> S;
    cin>>strInput;
    
    vector <char> line(strInput.begin(), strInput.end());  

    cout << dismiss(line, S);       
}



