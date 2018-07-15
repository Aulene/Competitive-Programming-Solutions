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

vector < pair <int, int> > g[100007];
vector <int> qs;
int p, ans;

bool cmp(pair <int, int> a, pair <int, int> b)
{
	return a.s < b.s;
}

void dfs(int idx, int parent, int dist)
{
	if(dist == 0)
		{
			if(idx == p) ans++;
			return;
		}

	if(g[idx].size() == 1) return dfs(g[idx][0].f, idx, dist - 1);

	if(parent == g[idx][0].f) dfs(g[idx][1].f, idx, dist - 1);
	else dfs(g[idx][0].f, idx, dist - 1);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w, q;

		cin >> n >> m >> p;
		
		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				g[u].pb(mp(v, i));
				g[v].pb(mp(u, i));
			}

		for(i = 0; i < n; i++)
			{
				sort(g[i].begin(), g[i].end(), cmp);

				g[i].resize(min(g[i].size() * 1ULL, 1ULL * 2));
				
				// cout << i << endl;
				// for(j = 0; j < g[i].size(); j++) cout << g[i][j].f << " "; cout << endl;
			}

		cin >> q;

		while(q--)
			{
				ans = 0;

				cin >> u;
				for(int i = 0; i < n; i++) dfs(i, -1, u);
				cout << ans << " ";
			}
		return 0;
	}