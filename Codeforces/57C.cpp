#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int f[200007], ans[100007];

long long pow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD; 
        b /= 2;
    }
    return x;
}
 
/*  Modular Multiplicative Inverse
    Using Euler's Theorem
    a^(phi(m)) = 1 (mod m)
    a^(-1) = a^(m-2) (mod m) */
long long InverseEuler(int n, int MOD)
{
    return pow(n,MOD-2,MOD);
}
 
long long C(int n, int r, int MOD)
{
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
 

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v, i, j;

		cin >> n;
		n--;

		f[1] = 1;
		for(i = 2; i < 200007; i++) f[i] = (f[i - 1] * i) % mod;

		int ansx = C(2 * n + 1, n + 1, mod);
		
		// cout << ansx << endl;

		ansx = (ansx * 2) % mod - (n + 1);
		ansx = (ansx + mod) % mod;

		if(n == 0) ansx = 1;
		cout << ansx  << endl;
		return 0;
	}