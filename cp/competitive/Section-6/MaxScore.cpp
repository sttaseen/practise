#include<bits/stdc++.h>
using namespace std;
#define print2(a,m,n)  

void print(vector<vector<int>> a, int m, int n){
    for(int i = 0; i < m; i++){
        for (int j=0; j<n; j++){
            cout<< a[i][j]<< " ";
        }
        cout << endl;
}
}

int matrixScore(vector<vector<int>> grid) {
    int ans=0,n=grid.size(),m=grid[0].size();
    cout << "m: " << m << " n: " << n <<endl;
    ans=(1<<(m-1))*n;
    cout << "ans1: " << ans <<endl;
    for(int j=1;j<m;j++)
    {
        cout << "j: " << j << endl;
        int val=1<<(m-1-j);
        cout << "val: " << val << endl;
        int sets=0;
        for(int i=0;i<n;i++)
        {
            if(grid[i][j]==grid[i][0])
            {
                sets++;
                cout << "sets: " << sets << endl;
            }
        }
        ans+=max(sets,n-sets)*val;
        cout << "ans: " << ans << endl;
    }
    return ans;
}

int main(void){
    vector<vector<int>> grid 
    {{0,0,1,1},
    {1,0,1,0},
    {1,1,0,0}};
    cout << "Score: " << matrixScore(grid);
}