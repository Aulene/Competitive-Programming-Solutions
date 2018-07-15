#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

bool h[100007];
int dist[100007];
vector < pair <int, int> > g[100007];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

void dijkstra(int n)
{
	int i, v, d;
	vector< pair <int, int> >::iterator it;

	for(i=1; i<=n; i++)
		if(h[i] == 0) dist[i]=LLONG_MAX;

	pair <int, int> pz, nx;
	
	for(i = 1; i <= n; i++)
		if(h[i]) pq.p(mp(i, dist[i]));

	while(!pq.empty())
		{
			v=pq.top().first;
			d=pq.top().second;
			pq.pop();

			for(it=g[v].begin(); it!=g[v].end(); it++)
				if(dist[it->first] > it->second+d)
					{
						dist[it->first]=it->second+d;
						pq.p(mp(it->first, dist[it->first]));
					}
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, p, i, j, u, v, w;

		cin >> n >> m >> p;

		for(i = 0; i < p; i++)
			{
				cin >> u;
				h[u] = 1;
			}

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> w;
				g[u].pb(mp(v, w));
				g[v].pb(mp(u, w));
			}

		dijkstra(n);

		for(i = 1; i <= n; i++)
			if(h[i] == 0)
				{
					if(dist[i] == LLONG_MAX) dist[i] = -1; 
						cout << i << " " << dist[i] << endl;
				}
		return 0;
	}