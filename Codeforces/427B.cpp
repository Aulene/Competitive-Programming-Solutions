#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int f[200007];
 
void facts()
{
	f[0] = 1;
	for(int i = 1; i < 200007; i++)
		f[i] = (f[i - 1] * i) % mod; 
}
 
int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
	    {
	        int q = a / m;
	        int t = m;
 
	        m = a % m, a = t;
	        t = y;
	 
	        y = x - q * y;
	        x = t;
	    }
 
    // Make x positive
    if (x < 0)
       x += m0;
 
    return x;
}
 

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		facts();

		int n, m, k, i, j, u = 0, v, ans;

		cin >> n >> m >> k;

		for(i = 0; i < n; i++) {
			cin >> v;
			if(v <= m) u++;
		}

		if(k > u) cout << "0" << endl;
		else {
			ans = f[u] / (f[u - k] * f[k]);
			cout << ans << endl;
		} 

		return 0;
	}