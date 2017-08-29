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

vector < vector <int> > g (100007);
int dp[100007]; bool vis[100007];

int dfs(int index, int x)
{
	if(dp[index] < x || vis[index]) return 0;

	vis[index] = 1;

	for(int i = 0; i < g[index].size(); i++)
		dfs(g[index][i], x + 1);
	
	dp[index] = x;
	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, u, v, q;

		cin >> n;

		for(i = 0; i < n - 1; i++) { cin >> u >> v; g[u].pb(v), g[v].pb(u); }
		for(i = 0; i < 100007; i++) dp[i] = 10000000007;

		dfs(1, 0);
		dp[1] = 0;
 
		cin >> q;

		while(q--)
			{
				cin >> u >> v;
				i = (dp[u] + dp[v]) % 2;
				if(i == 1) cout << "Odd" << endl;
				else cout << "Even" << endl;
			}
		return 0;
	}