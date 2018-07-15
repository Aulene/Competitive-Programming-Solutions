#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[4007], dp[4007][4007];
int vs[1000007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v = 1, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> u;
				if(vs[u]) a[i] = vs[u];
				else a[i] = v, vs[u] = v++;
			}



		// for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j < i; j++) 
					{
						dp[a[i]][a[j]] = 1 + max(dp[a[j]][a[i]], 1LL);
					}
			}

		for(i = 1; i <= 4000; i++)
			for(j = 1; j <= 4000; j++) ans = max(ans, dp[i][j]);

		cout << ans << endl;

		return 0;
	}