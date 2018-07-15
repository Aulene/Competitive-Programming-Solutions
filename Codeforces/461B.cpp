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
bool b[100007];
int dp[100007][7];

int dfs(int idx, int parent)
{
	dp[idx][0] = !b[idx];
	dp[idx][1] = b[idx];

	for(int i = 0; i < g[idx].size(); i++)
		{
			int u = g[idx][i];
			
			if(u != parent)
				{
					dfs(u, idx);

					int x = dp[idx][0], y = dp[idx][1];
					
					dp[idx][0] = dp[idx][1] = 0;

					dp[idx][0] = (dp[u][1] * x) % mod;
					dp[idx][1] = (dp[u][1] * y) % mod;

					dp[idx][1] = (dp[idx][1] + ((dp[u][0] * y) % mod + (dp[u][1] * x) % mod) % mod) % mod;
					dp[idx][0] = (dp[idx][0] + (dp[u][0] * x) % mod) % mod;
				}	
		}

	return 0;
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u;
				g[u].pb(i + 1);
				g[i + 1].pb(u);
			}

		for(i = 0; i < n; i++) 
			cin >> b[i];
		
		dfs(0, -1);
		cout << dp[0][1] << endl;

		return 0;
	}