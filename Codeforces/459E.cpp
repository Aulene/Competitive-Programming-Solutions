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

int mx = 100002;

vector < vector < pair <int, int> > > vs(100007);
int dp[300007];
int fuck[300007];
	
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w, x, ans, ansidx;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> w;
				vs[w].pb(mp(u, v));
			}

		for(i = 0; i < mx; i++)
			if(vs[i].size())
				{
					for(j = 0; j < vs[i].size(); j++) fuck[vs[i][j].s] = 0;

					for(j = 0; j < vs[i].size(); j++) {
						u = vs[i][j].f, v = vs[i][j].s;
						fuck[v]	= max(fuck[v], dp[u] + 1);
					}

					for(j = 0; j < vs[i].size(); j++) {
						u = vs[i][j].f, v = vs[i][j].s;
						dp[v] = max(dp[v], fuck[v]);
					}
				}

		ans = 0;

		for(i = 1; i <= n; i++)
			ans = max(ans, dp[i]);
	
		cout << ans << endl;
		return 0;
	}