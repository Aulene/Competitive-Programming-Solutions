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

vector < vector <int> > g(50007);
int dp[500007];
int m, ans = 0;

void dfs(int index, int parent, int dist)
{
	dp[dist]++;

	if(dist >= m) ans += dp[]
	for(int i = 0; i < g[index].size(); i++)
		{
			int u = g[index][i];

			if(u != parent)	
				dfs(u, index, dist + 1);
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v); g[v].pb(u);
			}

		dfs(1, 0, 0);

		for(i = 1; i <= n; i++) dp[dist[i]]++;

		return 0;
	}