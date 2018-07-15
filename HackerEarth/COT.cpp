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
int dp[50007][107];
int a[50007];

int dfs(int idx, int parent)
{
	dp[a[idx]]++;
	
	for(int i = 0; i < g[idx].size(); i++)
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, m, i, j, k, u, v;

		cin >> t;

		while(t--)
			{
				cin >> n >> k;
				
				for(i = 0; i < n; i++) g[i].clear();

				for(i = 0; i < 500007; i++)
					for(j = 0; j < 107; j++) dp[i][j] = 0;	
				
				for(i = 1; i <= n; i++) cin >> a[i];

				for(i = 0; i < n - 1; i++)
					{
						cin >> u >> v;
						g[u].pb(v);
						g[v].pb(u);
					}


			}

		return 0;
	}