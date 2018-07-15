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


vector < vector <int> > g(300007);
int color[300007], a[300007];
int dp[300007][27];
bool vis[300007];
int white = 0, grey = 1, black = 2;
int ans = 0;

bool cycle(int x)
{
	color[x] = grey;
	vis[x] = 1;

	for(int i = 0; i < g[x].size(); i++)
		{
			int y = g[x][i];
			vis[y] = 1;
			if(color[y] == grey) return 1;
			if(color[y] == white && cycle(y)) return 1;
		}
	color[x] = black;
	return 0;
}

	
void dfs(int idx)
{
	vis[idx] = 1;

	for(int i = 0; i < g[idx].size(); i++) 
		{
			int u = g[idx][i];

			if(!vis[u]) dfs(u);

			for(int j = 0; j < 26; j++) 
				dp[idx][j] = max(dp[idx][j], dp[u][j]);
		}

	dp[idx][a[idx]]++;
	ans = max(ans, dp[idx][a[idx]]);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		string s;
		bool cyl = 0;

		cin >> n >> m >> s;
		
		for(i = 0; i < n; i++)
			a[i + 1] = (int) s[i] - 'a';

 		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
			}

		for(int i = 1; i <= n; i++)
			{
				if(!vis[i]) cyl = max(cyl, cycle(i));
				if(cyl) break;
			}

		memset(vis, 0, sizeof(vis));

		if(cyl) cout << -1 << endl;
		else 
			{
				for(int i = 1; i <= n; i++)
					if(!vis[i]) dfs(i);
				cout << ans << endl;
			}
		return 0;
	}