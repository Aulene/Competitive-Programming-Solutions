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

int a[100007], leaf[100007];
vector <int> g[100007];
int ans = 0;
int m;

int dfs(int idx, int p, int lvl)
{
	if(lvl > m) return 0;
	
	if(a[idx]) lvl++;
	if(lvl <= m && leaf[idx]) ans++;

	if(a[idx] == 0) lvl = 0;

	// cout << idx << " " << lvl << endl;	
	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p)
			dfs(g[idx][i], idx, lvl);
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v); g[v].pb(u);
			}

		for(i = 2; i <= n; i++)
			if(g[i].size() == 1)
				{
					leaf[i] = 1;
				}

		dfs(1, -1, 0);
		cout << ans << endl;

		return 0;
	}