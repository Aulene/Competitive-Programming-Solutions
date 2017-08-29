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
int a[100007], b[100007], dp[100007], pick[100007];
int ans = 0;

int dfs(int index, int p, int pp)
{
	if(a[index] == b[index])
		{
			if(dp[pp] % 2 == 0) dp[index] = dp[pp];
			else dp[index] = dp[pp] + 1, pick[index] = 1, ans++;
		}
	else
		{
			if(dp[pp] % 2 == 1) dp[index] = dp[pp];
			else dp[index] = dp[pp] + 1, pick[index] = 1, ans++;			
		}

	for(int i = 0; i < g[index].size(); i++)
		if(g[index][i] != p)
			dfs(g[index][i], index, p);

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, u, v, i, j;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}	

		for(i = 1; i <= n; i++) cin >> a[i];
		for(i = 1; i <= n; i++) cin >> b[i];		
		dfs(1, 0, 0);	
		cout << ans << endl;
		for(i = 1; i <= n; i++) if(pick[i]) cout << i << endl;

		return 0;
	}