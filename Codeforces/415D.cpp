#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[2007][2007]; //no of seq of length i that end in j
vector < vector <int> > vs(2007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, sum;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			for(j = i; j <= n; j += i) vs[j].pb(i);

		for(i = 1; i <= n; i++) dp[1][i] = 1;

		for(i = 2; i <= m; i++)
			{
				for(j = 1; j <= n; j++)
					{
						sum = 0;

						for(k = 0; k < vs[j].size(); k++)
							sum = (sum + dp[i - 1][vs[j][k]]) % mod;

						dp[i][j] = sum;
					}
			}

		int ans = 0;

		for(i = 1; i <= n; i++) ans = (ans + dp[m][i]) % mod;

		cout << ans << endl;

		return 0;
	}