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

vector < vector < pair <int, int> > > g(107);
bool vis[107];
int u, v, c;

bool dfs(int index)
{
	if(index == v) return 1;

	if(vis[index]) return 0; vis[index] = 1;

	bool ans = 0;
	
	for(int i = 0; i < g[index].size(); i++) 
		if(g[index][i].s == c) 
			ans = max(ans, dfs(g[index][i].f));

	return ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, w, q, ans;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			cin >> u >> v >> w, g[u].pb(mp(v, w)), g[v].pb(mp(u, w));

		cin >> q;

		while(q--)
			{
				ans = 0;

				cin >> u >> v;

				for(c = 1; c <= m; c++) 
					{
						for(i = 0; i < 107; i++) 
							vis[i] = 0; 
						ans += dfs(u);
					}

				cout << ans << endl;
			}

		return 0;
	}