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

int h[107], g[107];
int dp[107][207][1007];
int p, q, n;

int recur(int i, int j, int k)
{
	if(j < 1 && i == n - 1) return 0;

	if(j < 1) return recur(i + 1, h[i + 1], k);

	if(dp[i][j][k] != -1) return dp[i][j][k];

	int ans = recur(i, j - q, k + 1), gEarned;

	if(k)
		{
			if(j <= p) gEarned = g[i];
			else gEarned = 0;

			ans = max(ans, gEarned + recur(i, j - p, k - 1));
		}

	return dp[i][j][k] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j, k, ans;

		cin >> t;

		for(int T = 1; T <= t; T++)
			{
				cin >> p >> q >> n;

				for(i = 0; i < n; i++)
					cin >> h[i] >> g[i];

				for(i = 0; i < 107; i++)
					for(j = 0; j < 207; j++)
						for(k = 0; k < 1007; k++)
							dp[i][j][k] = -1;

				ans = recur(0, h[0], 1);
				
				printf("Case #%lld: %lld\n", T, ans);
			}	
		return 0;
	}