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

int a[200007], ans[200007];
vector < vector <int> > g(200007);
vector <int> divs;
int vs[200007];
bool vis[200007];

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a % b);
}

void dfs(int index, int parent, int dist)
{
	int i, j;

	for(i = 0; i < divs.size(); i++)
		{
			vs[i] += (a[index] % divs[i] == 0);
			if(vs[i] >= dist) ans[index] = max(ans[index], divs[i]);
		}

	for(i = 0; i < g[index].size(); i++)
		if(g[index][i] != parent)
			dfs(g[index][i], index, dist + 1);

	for(i = 0; i < divs.size(); i++)
		vs[i] -= (a[index] % divs[i] == 0);
}

void dfs2(int index, int parent, int dist)
{
	int i, j;

	for(i = 0; i < g[index].size(); i++)
		if(g[index][i] != parent)
		{
			ans[g[index][i]] = gcd(ans[index], a[g[index][i]]);
			dfs2(g[index][i], index, dist + 1);
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);	
		cin.tie(NULL);

		int n, i, u, v;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i < n; i++)
			{
				cin >> u >> v;
				g[u].pb(v), g[v].pb(u);
			}

		u = a[1];

		a[1] = 0;
		dfs2(1, 0, 0);

		a[1] = u;
		for(i = 1; i * i <= u; i++)
			if(u % i == 0) divs.pb(i), divs.pb(u / i);
		
		sort(divs.begin(), divs.end());
		dfs(1, 0, 0);

		for(i = 1; i <= n; i++) cout << ans[i] << " ";

		return 0;
	}