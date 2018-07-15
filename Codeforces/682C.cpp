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

int a[100007];
vector < pair <int, int> > g[100007];
int ans = 0;

void dfs(int idx, int parent, int dist)
{
	if(dist > a[idx]) return;

	ans++;

	if(dist < 0) dist = 0;

	for(int i = 0; i < g[idx].size(); i++)
		{
			if(g[idx][i].f != parent)
				dfs(g[idx][i].f, idx, dist + g[idx][i].s);
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, w;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 2; i <= n; i++)
			{
				cin >> u >> w;
				v = i;
				
				g[u].pb(mp(v, w)), g[v].pb(mp(u, w));
			}

		dfs(1, 0, 0);

		// cout << ans << endl;
		cout << n - ans << endl;

		return 0;
	}