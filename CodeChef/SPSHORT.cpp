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

vector < pair <int, int> > g[10007];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;
int dist[10007], a[10007];

void dijkstras(int src)
{
	int i, j, u, v, x, y;

	for(i = 0; i < 100	07; i++) dist[i] = 1000000000007;
	dist[src] = 0;

	pq.p(mp(src, dist[src]));

	while(!pq.empty())
		{
			pair <int, int> pz = pq.top();
			pq.pop();

			u = pz.f, v = pz.s;
			
			for(i = 0; i < g[u].size(); i++)
				{
					pair <int, int> nz = g[u][i];

					x = nz.f, y = nz.s;

					if(dist[x] > v + y)
						{
							dist[x] = v + y;

							if(dist[x] < ans) pq.p(mp(x, dist[x]));
						}
				}
		}

	for(i = 0; i < s.size(); i++)
		if(src != s[i]) ans = min(ans, dist[s[i]]);
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, w, m;
		int src, sink;

		cin >> t;

		while(t--)
			{
				cin >> n >> m;
				
				
				for(i = 0; i < m; i++)
					{
						cin >> u >> v >> w;
						g[u].pb(mp(v, w));
						g[v].pb(mp(u, w));
					}

				cin >> src >> sink;

				g.clear();
			}
		return 0;
	}