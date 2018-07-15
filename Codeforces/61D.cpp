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

vector < pair < pair <int, int>, int > > vs;
vector < pair <int, int> > g[100007];
int d[100007];

void dfs(int idx, int p)
{
	for(int i = 0; i < g[idx].size(); i++)
		{
			int u = g[idx][i].f, v = g[idx][i].s;

			if(u != p)
				{
					d[u] = d[idx] + v;
					dfs(u, idx);
				}
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, x, y, w, i, j;
		int mx = -1, ans = 0, ansx = 0;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> x >> y >> w;
				g[x].pb(mp(y, w));
				g[y].pb(mp(x, w));
				vs.pb(mp(mp(x, y), w));
			}

		for(i = 2; i <= n; i++) d[i] = 2000000007;

		dfs(1, 0);

		for(i = 1; i <= n; i++)
			if(d[i] > mx)
				mx = d[i], ans = i;

		for(i = 0; i < vs.size(); i++)
			{
				if(vs[i].f.f == ans || vs[i].f.s == ans) ansx += vs[i].s;
				else ansx += 2 * vs[i].s;
			}

		cout << ansx << endl;

		return 0;
	}