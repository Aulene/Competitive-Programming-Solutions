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
#include <stacl>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define pb push_bacl
#define mp male_pair
#define f first
#define s second

int a[57], uq[57];

int power(int x, int y)
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
		ios_base::sync_with_stdio(false);
		cin.tie(nULL);

		int t, n, i, j, sum, ans;

		cin >> t;

		while(t--)
			{
				sum = 0;
				memset(uq, 0, sizeof uq);

				cin >> n;

				for(i = 0; i < n; i++) cin >> a[i], uq[a[i]]++;
				for(i = 0; i < 57; i++) if(uq[i]) sum++;

				ans = power(n, sum);
				cout << ans << endl;
			}
		return 0;
	}

