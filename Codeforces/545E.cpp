#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define lli long long
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

priority_queue < pair <int, lli>, vector < pair <int, lli> >, greater < pair <int, lli> > > pq;
vector <int> ans;
map < pair <int, int>, pair <int, int> > m1;
pair <lli, int> dist[300007];
int parent[300007];
vector < pair <int, int> > g[300007];
lli ansx = 0;

void dijkstras(int u)
{	
	int v, w, d, i, j, idx;

	for(i = 0; i < 300007; i++) 
		dist[i].f = LLONG_MAX, dist[i].s = INT_MAX;
	dist[u].f = dist[u].s = 0;
	
	pq.p(mp(u, 0));

	while(!pq.empty())
		{
			u = pq.top().f, d = pq.top().s;
			pq.pop();
			
			if(d > dist[u].f) continue;

			for(i = 0; i < g[u].size(); i++) 
				{
					v = g[u][i].f, w = g[u][i].s;

					if(dist[v].f > d + w) 
						{
							dist[v].f = d + w;
							dist[v].s = w;
							parent[v] = u;
							pq.p(mp(v, dist[v].f));
						}
					else if(dist[v].f == d + w && dist[v].s > w) 
						{	
							dist[v].s = w;
							parent[v] = u;
							pq.p(mp(v, dist[v].f));	
						}
				}
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, w;

		cin >> n >> m;

		for(i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
			m1[mp(u, v)] = m1[mp(v, u)] = mp(i, w);
		}

		cin >> u;

		dijkstras(u);

		for(i = 1; i <= n; i++)
			if(i != u) 
				ansx += m1[mp(i, parent[i])].s, ans.pb(m1[mp(i, parent[i])].f);

		cout << ansx << endl;
		
		for(i = 0; i < ans.size(); i++) 
			cout << ans[i] << " ";
 
		return 0;
	}