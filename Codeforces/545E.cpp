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

vector < pair <int, int> > g[300007];
map < pair <int, int>, int > mx;
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > >  pq;
int dist[300007];

void dijkstras(int u)
{
	for(int i = 0; i < 300007; i++) dist[i] = INT_MAX;
	dist[u] = 0;

	pq.p(mp(u, 0));

	while(!pq.empty())
		{
			
		}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w;

		cin >> n >> m;

		for(i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			g[u].pb(mp(v, w));
			g[v].pb(mp(u, w));
			mx[mp(u, v)] = mx[mp(v, u)] = i;
		}

		cin >> u;

		return 0;
	}