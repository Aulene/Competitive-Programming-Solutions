#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int a[27];
int val[27][27];
int dp[27][300007];
int n, m;

int recur(int idx, int mask)
{
	int setbits = __builtin_popcount(mask);

	if(setbits == m)
		{
			bitset <20> c(mask);
			// cout << c << " " << setbits << endl;
			return a[idx];
		}

	if(dp[idx][mask] != -1) 
		return dp[idx][mask];

	int ans = 0, u, nmask;

	for(int i = 0; i < n; i++)
		{
			u = mask & (1 << i);

			if(!u)
				{
					nmask = mask | (1 << i);
					ans = max(ans, recur(i, nmask) + val[idx][i]);
				}
		}

	return dp[idx][mask] = ans + a[idx];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int k, i, j, u, v, w, mask, ans = 0;

		for(i = 0; i < 27; i++)
			for(j = 0; j < 300007; j++) dp[i][j] = -1;

		cin >> n >> m >> k;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < k; i++) {
			cin >> u >> v >> w;
			u--, v--;
			val[u][v] = w;
		}

		for(i = 0; i < n; i++)
			{
				mask = 0 | (1 << i);
				ans = max(ans, recur(i, mask));
			}

		cout << ans << endl;

		return 0;
	}