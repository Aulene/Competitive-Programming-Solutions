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

vector <int> g[3007];
int ans[3007];

int dfs(int idx, int p, int len)
{
	// cout << idx << " " << p << endl;

	if(len == 2)
		{
			ans[idx]++; 
			return 0;
		}

	for(int i = 0; i < g[idx].size(); i++)
		// if(!vis[idx][g[idx][i]])
			dfs(g[idx][i], idx, len + 1);
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ansx = 0;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
			}

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= n; j++) ans[j] = 0;

				dfs(i, -1, 0);

				for(j = 1; j <= n; j++)
					if(i != j) ansx += ans[j] * (ans[j] - 1) / 2;
				
				// cout << endl;
			}
	
		// for(i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
		cout << ansx << endl;

		return 0;
	}