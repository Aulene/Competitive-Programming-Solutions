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
#define mod 10243
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[2507][107], dp2[2507][107]; // numbers of ways to choose j from i
int n, m;
vector < vector <int> > g(100007);

int dfs(int index, int parent, int left)
{
	if(left == 0) return 1;

	if(dp[index][left] != -1) return dp[index][left];

	int ans = 0;
	
	for(int i = 0; i < left; i++)
		{
			
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, u, v;

		cin >> n >> m;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i = 0; i < 2507; i++)
			for(j = 0; j < 107; j++) dp[i][j] = -1;

		return 0;
	}