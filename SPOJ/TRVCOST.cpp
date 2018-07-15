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
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq; 
int dist[100007];

void dijkstra(int src)
{
	for(int i = 0; i < 100007; i++) dist[i] = INT_MAX;
	dist[src] = 0;

	pq.p(mp(src, dist[src]));
	pair <int, int> pz;

	while(!pq.empty())
		{
			pz = pq.top();
			pq.pop();

			int u = pz.f, v = pz.s;

			for(int i = 0; i < g[u].size(); i++)
				{
					int x = g[u][i].f, y = g[u][i].s;

					if(dist[x] > v + y)
						{
							dist[x] = v + y;
							pq.p(mp(x, dist[x]));
						}
				}
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, u, v, i, j, w, q;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v >> w;
				g[u].pb(mp(v, w)), g[v].pb(mp(u, w));
			}

		cin >> u >> q;

		dijkstra(u);

		while(q--)
			{
				cin >> v;
				if(dist[v] == INT_MAX) cout << "NO PATH\n";
				else cout << dist[v] << endl;
			}
		return 0;
	}