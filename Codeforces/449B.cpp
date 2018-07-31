#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > vs[300007];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;
int dist[100007], ok[100007];
int tot = 0, k;

void dijkstra()
{
	pq.p(mp(1, 0));

	while(!pq.empty())
		{
			pair <int, int> pz = pq.top();
			pq.pop();

			int u = pz.f, v = pz.s;

			for(int i = 0; i < vs[u].size(); i++)
				{
					int x = vs[u][i].f, w = vs[u][i].s;

					if(dist[x] > v + w) {
						// cout << x << endl;
						ok[x] = 0;
						dist[x] = v + w;
						pq.p(mp(x, dist[x]));
					}
					else if(dist[x] == v + w) ok[x] = 0;
				}
		}

	return;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w, ans = 0;

		cin >> n >> m >> k;

		int K = k;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> w;
				vs[u].pb(mp(v, w));
				vs[v].pb(mp(u, w));
			}

		for(int i = 0; i < 100007; i++) 
			dist[i] = INT_MAX; 
		dist[1] = 0;

		for(i = 0; i < k; i++)
			{
				cin >> u >> w;

				if(dist[u] == INT_MAX) {
					dist[u] = w;
					ok[u] = 1;
					continue;
				}

				if(dist[u] > w) {
					dist[u] = w;
					K--, tot++;
				}

				if(dist[u] <= w) 
					K--, tot++;
			}

		for(i = 1; i <= n; i++) pq.p(mp(i, dist[i]));

		dijkstra();

		// for(int i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;
		// for(int i = 1; i <= n; i++) cout << ok[i] << " "; cout << endl;
		// cout << tot << endl;

		for(i = 1; i <= n; i++) 
			if(ok[i]) ans++;

		printf("%lld\n", tot + K - ans);

		return 0;
	}