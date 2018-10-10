#include<iostream>
 
using namespace std;
 
const int N=1000001, MOD=10000;
int f[1000007], g[1000007];
 
int recur(int n)
{
    f[0] = 0; f[1] = 1; f[2] = 2;
    g[0] = 0; g[1] = 1; g[2] = 2;
 
    for(int i = 3; i < N; i++) {
        f[i] = (f[i - 1] + f[i - 2] + 2 * g[i - 2]) % MOD;
        g[i] = (f[i - 1] + g[i - 1]) % MOD;
    }

    return f[n];
}
 
int main()
{
    int n;
    cin >> n;
    cout << recur(n) << endl;
    
    cout << g[3] << endl;
    
    return 0;
}