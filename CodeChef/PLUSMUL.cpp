//modexp from gfg -- http://www.geeksforgeeks.org/modular-exponentiation-y-in-modular-arithmetic/

#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

lli a[100007];

lli exponent(lli x, lli y)
{
	lli ans = 1;
	x = x % mod;
	
	while(y > 0)
		{
			if(y & 1)
				ans = (ans * x) % mod;
				
			y = y >> 1;
			x = (x * x) % mod;
		}
	
	return ans;
}

int main()
	{
		ios::sync_with_stdio(false);	
		cin.tie(NULL);

		lli t, i, sum, ans, prod, f, n;

		cin >> t;

		while(t--)
			{
				sum = 0, prod = 1, f = 1;

				cin >> n;

				for(i=0; i<n; i++)
					{
						cin >> a[i];
						
						sum = (sum + a[i]) % mod;
						prod = (prod * a[i]) % mod;
					}

				if(n > 1)
					f = exponent(2, n-2);

				sum = (sum * f) % mod;
				prod = (prod * f) % mod;

				if(n == 1)
					ans = a[0];
				else
					{
						ans = (sum + prod) % mod;
						if(ans < 0)
							ans += mod;
					}

				cout << ans << endl;
			}
		return 0;
	}