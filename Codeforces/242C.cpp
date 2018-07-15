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

map < pair <int, int>, int> g;
map < pair <int, int>, int> dist;
map < pair <int, int>, int> vis;

int dx[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, -1, 1};

int bfs(pair <int, int> s, pair <int, int> e)
{
	queue < pair < pair <int, int>, int> > q;
	q.p(mp(s, 0));

	while(!q.empty())
		{
			pair < pair <int, int>, int> pz = q.front();
			q.pop();

			if(!g[pz.f]) continue;

			int u = pz.f.f, v = pz.f.s, w = pz.s;
			
			for(int i = 0; i < 8; i++)
				{
					int x = u + dx[i], y = v + dy[i];

					if(g[mp(x, y)])
						{
							if(vis[mp(x, y)] == 0) {
								vis[mp(x, y)] = 1;
								dist[mp(x, y)] = 100007;
							}

							if(dist[mp(x, y)] > w + 1) {
								dist[mp(x, y)] = w + 1;
								q.p(mp(mp(x, y), w + 1));
							}
						}
				}
		}

	if(dist[e] >= 100007 || !g[e] || !vis[e]) 
		return -1;
	return dist[e];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, a, b, c, d;
		int u, v, w, i, j;

		cin >> a >> b >> c >> d >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v >> w;
				for(j = v; j <= w; j++) g[mp(u, j)] = 1;
			}

		cout << bfs(mp(a, b), mp(c, d)) << endl;

		return 0;
	}