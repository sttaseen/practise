#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 200005;
const int sz = 2;
const int mod = 1e9+7;

struct Vec {
    int v[sz];
    Vec() {
        memset(v, 0, sizeof(v));
    }
};


struct Mat {
    int m[sz][sz];
    Mat() {
        memset(m, 0, sizeof(m));
    }

    void ones() {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                 m[i][j] = 1; 
            }                         
        }        
    }

    void identity() {
        for (int i = 0; i < sz; i++)
        {
            m[i][i] = 1;                        
        }        
    }

    Mat operator* (Mat& mat){
        Mat res;
        for (int i = 0; i < sz; i++)
        {
            for (int k = 0; k < sz; k++)
            {
                for (int j = 0; j < sz; j++)
                {   
                    res.m[i][k] += (m[i][j] * mat.m[j][k])%mod;
                }
                res.m[i][k]%=mod;            
            }
            
        }
        return res;        
    }  
    

    Vec operator* (Vec& vec){
        Vec res;
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                res.v[i] += (m[i][j] * vec.v[j])%mod;
            }         
            res.v[i] %= mod;
        }  
        
        return res;  
    }  
};


int fib(int n){
    if (n<=2) return 1;
    if(n==3) return 2;

    n-=3;

    Mat T;
    T.ones();
    T.m[1][1] = 0;

    Vec x;
    x.v[0] = x.v[1] = 1;

    Mat Tf;
    Tf.identity();

    while(n){       
        if(n&1) Tf=T*Tf;
        T=T*T;      
        n/=2;
    }  

    Vec res = Tf*x;

    return res.v[0]+res.v[1];
}

int fibSum(int n, int m){
    return (fib(m+2)-fib(n+1)+mod)%mod;
}

void solve() {
    cout << fibSum(1, 1e9);
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

    int t = 1;
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}