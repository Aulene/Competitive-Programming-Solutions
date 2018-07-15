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

vector < pair <int, int> > g[107];
priority_queue < pair <int, int> , vector < pair <int, int> > , greater < pair <int, int> > > pq;
int dist[1007];
int a[107]; int ans[107];
int n;

int dijkstra(int source, int reach)
{
	int v, d, i;
	vector< pair <int, int> > ::iterator it;

	for(i  = 0; i <= n; i++)
		dist[i] = INT_MAX;
	dist[source] = 0;
	ans[source] = a[source];

	pq.p(mp(source, dist[source]));

	while(!pq.empty())
		{
			v = pq.top().first;
			d = pq.top().second;

			pq.pop();

			for(it = g[v].begin(); it != g[v].end(); it++)
				{
					int U = it -> first, V = it -> second;

					if(dist[U] > d + V)
						{
							dist[U] = d + V;
							ans[U] = a[U] + ans[v];
							pq.p(mp(U, dist[U]));
						}
					else if(dist[U] == d + V)
						{
							if(a[U] + ans[v] > ans[U])
								{
									ans[U] = a[U] + ans[v];
									pq.p(mp(U, dist[U]));
								}
						}
				}
		}

	return dist[reach];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, m, u, v, w;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		cin >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> w;
				g[u].pb(mp(v, w)), g[v].pb(mp(u, w));
			}

		int l = dijkstra(1, n);
		if(dist[n] == INT_MAX) cout << "impossible\n";
		else
			{
				cout << dist[n] << " " << ans[n] << endl;
			}
		return 0;
	}