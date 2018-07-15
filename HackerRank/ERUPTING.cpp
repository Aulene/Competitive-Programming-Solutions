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

int dp[307][307];
int add[307][307], vis[307][307];
int n;

int dfs(int x, int y, int val)
{
	if(x < 0 || x > n - 1 || y < 0 || y > n - 1 || val <= 0) return 0;
	// if(vis[x][y]) return 0;

	vis[x][y] = 1;

	add[x][y] = max(add[x][y], val);
	// cout << x << " " << y << " " << val << endl;

	dfs(x - 1, y, val - 1);
	dfs(x - 1, y - 1, val - 1);
	dfs(x - 1, y + 1, val - 1);

	dfs(x + 1, y, val - 1);
	dfs(x + 1, y - 1, val - 1);
	dfs(x + 1, y + 1, val - 1);

	dfs(x, y - 1, val - 1);
	dfs(x, y + 1, val - 1);

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, q, u, v, x;

		cin >> n >> q;

		while(q--)
			{
				cin >> u >> v >> x;

				for(i = 0; i < n; i++)
					for(j = 0; j < n; j++) add[i][j] = 0, vis[i][j] = 0;;

				dfs(u, v, x);

				for(i = 0; i < n; i++)
					for(j = 0; j < n; j++)
						dp[i][j] += add[i][j];
			}

		int ans = 0;

		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++) 
				ans = max(dp[i][j], ans);

		cout << ans << endl;
		return 0;
	}