#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(1007);
int sz[1007], cost[1007], a[1007];
bool removed[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= m; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
				sz[u]++, sz[v]++;
				cost[u] += a[v], cost[v] += a[u];
			}

		cost[n + 1] = mod;

		for(i = 1; i <= n; i++)
			{
				pair <int, int> rem = mp(n + 1, -mod);

				for(j = 1; j <= n; j++) 
					if(!removed[j])
						{
							if(a[j] > rem.s) {
								rem = mp(j, a[j]);
							}
							else if(a[j] == rem.s && sz[j] > rem.f) {
								rem = mp(j, a[j]);
							}
						}

				for(j = 0; j < g[rem.f].size(); j++) {
					sz[g[rem.f][j]]--;
					cost[g[rem.f][j]] -= a[rem.f];
				}

				removed[rem.f] = 1;
				ans += cost[rem.f];
 			}

		cout << ans << endl;

		return 0;
	}