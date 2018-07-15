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

vector <int> g[50007];
int ans[50007];

int dfs(int idx, int p)
{
	for(int i = 0; i < g[idx].size(); i++)
		{
			if(g[idx][i] != p)
				{
					ans[g[idx][i]] = idx;
					dfs(g[idx][i], idx);
					// cout << g[idx][i] << " " << idx << endl;
				}
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, r1, r2, u, v, i, j;

		cin >> n >> r1 >> r2;

		for(i = 1; i <= n; i++)
			{
				if(i == r1) continue;
				cin >> u;

				g[u].pb(i);
				g[i].pb(u);
			}

		dfs(r2, -1);

		for(i = 1; i <= n; i++)
			if(i != r2) cout << ans[i] << " ";
		return 0;
	}