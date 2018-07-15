#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], dp[100007];
vector < vector <int> > g (100007);

void dfs(int idx, int p, int lvl)
{
	dp[lvl]++;

	for(int i = 0; i < g[idx].size(); i++)
		dfs(g[idx][i], idx, lvl + 1);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 2; i <= n; i++)
			{
				cin >> u;
				g[u].pb(i);
			}

		dfs(1, 0, 1);

		for(i = 1; i <= n; i++)
			{
				u = dp[i] % 2;
				ans += u;
			}

		// for(i = 1; i <= n; i++) cout << dp[i] << " "; cout << endl;
		

		cout << ans << endl;

		return 0;
	}