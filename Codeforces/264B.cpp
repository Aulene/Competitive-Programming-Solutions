#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > vs (100007);
int a[100007], dp[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;

		for(i = 1; i <= 100000; i++)
			for(j = 2; j <= sqrt(i); j++)
				if(i % j == 0)
					{
						vs[i].pb(j);
						if(j != sqrt(i)) vs[i].pb(i / j);
					}

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++)
			{
				// cout << a[i] << endl;

				dp[a[i]] = 1;

				for(j = 0; j < vs[a[i]].size(); j++)
					if(vs[a[i]][j] != a[i])
					{
						// cout << vs[a[i]][j] << " " << 1 + dp[vs[a[i]][j]] << endl;
						dp[a[i]] = max(dp[a[i]], 1 + dp[vs[a[i]][j]]);
					}

				for(j = 0; j < vs[a[i]].size(); j++)
					dp[vs[a[i]][j]] = dp[a[i]];

				// cout << "DP[" << a[i] << "] = " << dp[a[i]] << endl;
			}

		for(i = 1; i <= 100000; i++) ans = max(ans, dp[i]);

		cout << ans << endl;

		return 0;
	}