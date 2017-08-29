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
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int vis[1000007], a[1000007], ans;

int exp(int x, int y)
{
    int res = 1;

    while (y > 0)
	    {
	        if (y & 1)
	            res = res * x;

	        y = y >> 1;
	        x = x * x; 
	    }

    return res;
}

int modexp(int x, int y, int mod)
{
    int res = 1; 

    x = x % mod; 
                
    while (y > 0)
	    {
	        if (y & 1)
	            res = (res * x) % mod;

	        y = y >> 1; 
	        x = (x * x) % mod;
	    }

    return res;
}


signed main() 
{
	int t, n, q, M, N, x, i, j, k, c, idx;
	int num, r, sz;
	char Q;

	cin >> t;

	while(t--)
		{
		    cin >> n >> q;
		    M = exp(2, n);
		    N = (M * 2) - 1;

		    ans = 1, x = 0;
		    for(i = 0; i < 1000007; i++) vis[i] = 0; vis[0] = 1;

		    while(q--)
			    {
			        cin >> Q;

			        if(Q == '?') cout << ans << endl;
			        else
				        {
				            cin >> c;
				           
				            x = (x % M + modexp(2, c, M)) % M;
				           
				            num = x, sz = 0, idx = 0;

				            while(num > 0)
				                {
				                	r = num % 2;
				                	a[sz++] = r;
				                    num /= 2;
				                }

			                for(i = sz; i < n; i++) a[i] = 0;

				            for(i = n - 1; i >= 0; i--)
					            {
					                if(!a[i]) idx = 2 * idx + 1;
					             	else idx = 2 * idx + 2;

						           	if(idx < N && !vis[idx]) ans++, vis[idx] = 1;
					            }
				        }
			    }
			}

	return 0;
}