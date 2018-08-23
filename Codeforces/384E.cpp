#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int a[200007], dp[100007];
vvi g(200007);
int finder;
bool found = 0;

void dfs(int idx, int p = -1)
{
	if(found) return;

	a[idx] += dp[idx];

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) dp[g[idx][i]] = dp[g[idx][i]] + (-dp[idx]);

	dp[idx] = 0;

	if(idx == finder) {
		found = 1;
		return;
	}

	for(int i = 0; i < g[idx].size(); i++) 
		if(g[idx][i] != p) dfs(g[idx][i], idx);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, q, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		while(m--)
			{
				cin >> q;

				if(q == 1)
					{
						cin >> u >> v;
						dp[u] += v;
					}
				else
					{
						cin >> finder;
						found = 0;
						dfs(1);
						cout << a[finder] << endl;
					}	
			}
		return 0;
	}