#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(200007);
bool vis[200007];
int fuck = 1;
int sz = 0;

void dfs(int idx)
{
	vis[idx] = 1;
	sz++;

	if(g[idx].size() != 2) 
		fuck = 0;

	for(int i = 0; i < g[idx].size(); i++)
		if(!vis[g[idx][i]])
			dfs(g[idx][i]);
}

int check(int idx)
{
	fuck = 1;
	sz = 0;

	dfs(idx);

	if(sz <= 2) fuck = 0;

	return fuck;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i = 1; i <= n; i++) 
			if(!vis[i])
				ans += check(i);

		cout << ans << endl;

		return 0;
	}