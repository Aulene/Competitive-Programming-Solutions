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

int dp[1000007];

int curver(int n)
{
	double ans = n;
	dp[0] = n;

	for(int i = 1; i <= 1000007; i++)
		{
			ans = (double) 10 * sqrt(ans);
			int ansx = ceil(ans);
			dp[i] = ansx;
		}
	return ans;
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, u, v, i, j, w;
		int a, b, c;
		bool lowfound = 0;

		cin >> a >> b >> c;

		curver(a);

		for(int i = 0; i < 1000007; i++)
			{
				if(dp[i] >= b && dp[i] <= c)
					{
						if(lowfound == 0)
							{
								lowfound = 1;
								u = i;
							}
						v = i;
					}
			}

		if(!lowfound) cout << "impossible\n";
		else if(v == 1000006) cout << u << " inf" << endl;
		else cout << u << " " << v << endl;

		return 0;
	}