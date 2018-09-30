#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 10007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define N 100017

vvi g(N);
int dp[N][7], dp2[N][7]; // dp2[i][0] = minimum lights to cover subtree at i without placing a light at i
			   // dp2[i][1] = minimum lights to cover subtree at i by placing a light at i				

pair <int, int> dfs(int idx, int p = -1)
{
	int ans = 0;
	pair <int, int> pz, mz = mp(0, 1);

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) {
			pz = dfs(g[idx][i], idx);
			mz.f += pz.s;
			mz.s += min(pz.f, pz.s);
		}

	dp2[idx][0] = mz.f, dp2[idx][1] = mz.s;
	return mz;
}

pair <int, int> dfs2(int idx, int p = -1)
{	
	int ans = 0;
	pair <int, int> pz, mz = mp(1, 1);

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) {

			pz = dfs2(g[idx][i], idx);
			mz.f = (mz.f * pz.s) % mod;

			int val = (pz.f + pz.s) % mod;

			if(dp2[g[idx][i]][0] < dp2[g[idx][i]][1]) 
				val = pz.f;
			else if(dp2[g[idx][i]][1] < dp2[g[idx][i]][0]) 
				val = pz.s;

			mz.s = (mz.s * val) % mod;
		}

	dp[idx][0] = mz.f;
	dp[idx][1] = mz.s;

	return mz;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		int t, n, m, i, j, u, v, ans, ans2;

		for(i = 0; i < N; i++)
			for(j = 0; j < 7; j++) 
				dp[i][j] = dp2[i][j] = -1;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < N; i++) g[i].clear();

				cin >> n;

				for(i = 0; i < n - 1; i++)
					{
						cin >> u >> v;
						g[u].pb(v), g[v].pb(u);
					}

				dfs(1);
				dfs2(1);

				// for(int i = 1; i <= n; i++)
				// 	printf("DP2[%lld][0] = %lld, DP2[%lld][1] = %lld\n", i, dp2[i][0], i, dp2[i][1]);

				// for(int i = 1; i <= n; i++)
				// 	printf("DP[%lld][0] = %lld, DP[%lld][1] = %lld\n", i, dp[i][0], i, dp[i][1]);

				if(dp2[1][0] < dp2[1][1]) 
					cout << dp2[1][0] << " " << dp[1][0] << endl;
				else if(dp2[1][1] < dp2[1][0]) 
					cout << dp2[1][1] << " " << dp[1][1] << endl;
				else cout << dp2[1][0] << " " << (dp[1][0] + dp[1][1]) % mod << endl;
			}

		return 0;
	}