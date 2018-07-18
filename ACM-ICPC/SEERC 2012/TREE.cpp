#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > g[50007];
int dist[50007], ans;
int a = 0, ax = 0;
int b = 0, bx = 0;

void dfs(int idx, int p = -1, int x = 0)
{
	dist[idx] = x;

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i].f != p) 
			dfs(g[idx][i].f, idx, x + g[idx][i].s);
}

void dfs2(int idx, int p = -1, int x = 0)
{
	dist[idx] = max(dist[idx], x);

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i].f != p) 
			dfs2(g[idx][i].f, idx, x + g[idx][i].s);
}

signed main()
	{
		int n, i, j, u, v, w;

		ifstream cin ("i.in");

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v >> w;
				g[u].pb(mp(v, w));
				g[v].pb(mp(u, w));
			}

		dfs(1);

		// for(i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;

		for(i = 1; i <= n; i++)
			if(ax < dist[i])
				a = i, ax = dist[i];

		for(i = 1; i <= n; i++) dist[i] = 0;

		dfs(a);

		for(int i = 1; i <= n; i++)
			if(bx < dist[i])
				b = i, bx = dist[i];

		// cout << a << " " << b << endl;

		for(int i = 1; i <= n; i++) dist[i] = 0;
			
		dfs2(a);
		dfs2(b);

		for(int i = 1; i <= n; i++) cout << dist[i] << endl;

		return 0;
	}