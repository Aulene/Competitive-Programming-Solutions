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

vector < vector <int> > g(100007);
bool sep[100007];

int dfs(int u, int p, int root)
{
	int vis = 0;

	if(p != 0) sep[u] = 0;

	for(int i = 0; i < g[u].size(); i++)
		{
			if(sep[g[u][i]] && g[u][i] != p)
				dfs(g[u][i], u, root);
			else if(!sep[g[u][i]] && g[u][i] != p) sep[root] = 0;
		}

	return 0;
}

signed main()
	{
			ios_base::sync_with_stdio(false);
			cin.tie(NULL);

		int n, m, u, v, i, j, ans = 0;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v), g[v].pb(u);
			}	

		for(i = 1; i <= n; i++) sep[i] = 1;

		for(i = 1; i <= n; i++) 
			if(sep[i]) j = dfs(i, 0, i);

		for(i = 1; i <= n; i++) if(sep[i]) ans++;

		cout << ans << endl;
		return 0;
	}