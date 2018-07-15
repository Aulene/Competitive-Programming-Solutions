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

		int t, i, u, v, w, x, y, z, n, denom, num;
		int right, down, ans;

		cin >> t;

		for(int j = 1; j <= t; j++)
			{
				ans = 0;
				cin >> u >> v >> x >> y;

				right = x - u;
				down = y - v;
				n = min(right, down);

				// cout << "RIGHT " << right << " DOWN " << down << endl;

				if(right == 0 && down == 0)
					ans = 1;
				else
					{
						for(i = 0; i <= n; i++)
							{
								num = ((f[right + down - i] % mod) * (f[right] % mod)) % mod;

								u = modInverse(f[down - i] % mod, mod);
								v = modInverse(f[right] % mod, mod);
								w = modInverse(f[right - i] % mod, mod); 
								y = modInverse(f[i] % mod, mod);

								x = (u * v) % mod;
								x = (x * w) % mod;
								x = (x * y) % mod;
								x = (x * num) % mod;


								ans = (ans + x) % mod;
							}
					}
				
				printf("Case %lld: %lld\n", j, ans);
			}

		return 0;
	}
