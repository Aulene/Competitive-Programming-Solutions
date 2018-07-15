#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector < pair <int, int> > > vs(100007);
vector < pair <int, int> > anus;
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;
int dist[100007];
int in[100007];

void dijkstra()
{
	for(int i = 0; i < 100007; i++) dist[i] = INT_MAX; dist[1] = 0;

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
						dist[x] = v + w;
						pq.p(mp(x, dist[x]));
					}
				}
		}

	return;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, k, i, j, u, v, w, ans = 0;

		cin >> n >> m >> k;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> w;
				vs[u].pb(mp(v, w));
				vs[v].pb(mp(u, w));
				in[u]++, in[v]++;
			}

		for(i = 0; i < k; i++)
			{
				cin >> u >> w;
				anus.pb(mp(u, w));
			}

		dijkstra();
		// for(int i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;

		for(i = 0; i < anus.size(); i++)
			{
				u = anus[i].f, v = anus[i].s;

				if(dist[u] >= v && in[u]) ans++;
			}

		cout << ans << endl;
		return 0;
	}