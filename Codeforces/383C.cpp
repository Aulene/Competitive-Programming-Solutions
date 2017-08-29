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

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[200007];
int subs[200007];

int dfs1(int index, int p)
{
	int nums = 0;


}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		return 0;
	}