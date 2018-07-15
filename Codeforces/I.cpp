#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[257][1007];
vector < pair<int, int> > g[100007];
priority_queue < pair <int, int> , vector < pair <int, int> > , greater < pair <int, int> > > pq;
int dist[100007];
int n;

int dijkstra(int source, int reach)
{
	int v, d, i;
	vector< pair <int, int> >::iterator it;

	for(i  = 0; i <= n; i++)
		dist[i] = INT_MAX;
	dist[source] = 0;

	pq.p(mp(source, dist[source]));

	while(!pq.empty())
		{
			v = pq.top().first;
			d = pq.top().second;

			pq.pop();

			for(it = g[v].begin(); it != g[v].end(); it++)
				if(dist[it -> first] > d + it -> second)
					{
						dist[it -> first] = d + it -> second;
						pq.p(mp(it -> first, dist[it -> first]));
					}
		}

	if(dist[reach] > 257) 
		return -1;

	return dist[reach];
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, m = 20, s, e, i, j, k, u, v;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 257; i++) g[i].clear();
				for(i = 0; i < 257; i++)
					for(j = 0; j < 1007; j++) a[i][j] = 0;

				cin >> n >> s >> e;

				string st;

				for(i = 1; i <= n; i++)
					{
						cin >> st;

						for(j = 0; j < m; j++)
							{
								int asshole = (int) (st[j] - '0');
								a[i][asshole]++;
							}
					}

				for(i = 1; i <= n; i++)
					{
						for(j = i + 1; j <= n; j++)
							{
								int fuck = 0;

								for(k = 0; k <= 9; k++)
									fuck += min(a[i][k], a[j][k]);

								// cout << i << " " << j << " " << fuck << endl;

								if(fuck >= 17) {
									g[i].pb(mp(j, 1)), g[j].pb(mp(i, 1));
									// cout << i << " " << j << endl;
								}
							}
					}

				cout << dijkstra(s, e) << endl;
			}
		return 0;
	}