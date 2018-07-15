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

int a[6007], dp[6007];
vector < vector <int> > g(100007);

int dfs(int index, int parent)
{
	if(dp[index] != -1) return dp[index];

	int ans = 0;
	for(int i = 0; i < g[index].size(); i++)
		{
			if(g[index][i] != parent)
				ans += dfs(g[index][i], index);
		}

	ans = max(ans, a[index]);
	return dp[index] = ans;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v, ans;

		cin >> n;

		for(int i = 1; i <= n; i++)
			cin >> a[i], dp[i] = -1;

		while(cin >> u >> v)
			{
				if(u == 0 && v == 0) break;
				g[v].pb(u); g[u].pb(v);
			}

		ans = dfs(1, 0);

		for(int i = 1; i <= n; i++) cout << dp[i] << " ";cout << endl;
		cout << ans << endl;
		return 0;
	}