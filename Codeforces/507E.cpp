#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > g[100007];
vector < pair < int, pair <int, int> > > ansv, vs;
priority_queue < pair <int, pair <int, int> >, vector < pair <int, pair <int, int> > >, greater < pair <int, pair <int, int> > > > pq;
int dist[100007], dist2[100007], parent[100007];
map < pair <int, int>, int> mx;

void fix(int idx)
{
    if(idx == -1) return;

    if(parent[idx] != -1)
    	mx[mp(idx, parent[idx])] = mx[mp(parent[idx], idx)] = 1;

    fix(parent[idx]);
    // cout << idx << " ";
}

int dijkstras()
{	
	for(int i = 2; i < 100007; i++) dist[i] = dist2[i] = INT_MAX;
	parent[1] = -1;

	pq.p(mp(1, mp(0, 0)));
	pair < int, pair <int, int> > pz;

	while(!pq.empty())
		{
			pz = pq.top();
			pq.pop();

			int u = pz.f, w = pz.s.f, w2 = pz.s.s;

			for(int i = 0; i < g[u].size(); i++)
				{
					int v = g[u][i].f, vw = g[u][i].s;

					if(dist[v] > w + 1) {
						dist[v] = w + 1;
						dist2[v] = w2 + vw;
						parent[v] = u;

						pq.p(mp(v, mp(dist[v], dist2[v])));
					}
					else if(dist[v] == w + 1) {
						if(dist2[v] < w2 + vw) {
							dist2[v] = w2 + vw;
							parent[v] = u;
							pq.p(mp(v, mp(dist[v], dist2[v])));
						}
					}
				}
		}

	return 0;
}	

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w;

		cin >> n >> m;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> w;
				g[u].pb(mp(v, w));
				g[v].pb(mp(u, w));
				vs.pb(mp(u, mp(v, w)));
			}

		dijkstras();
		fix(n);

		for(i = 0; i < m; i++)
			{
				u = vs[i].f, v = vs[i].s.f, w = vs[i].s.s;

				if((!w && mx[mp(u, v)]) || (w && !mx[mp(u, v)]))
					ansv.pb(mp(u, mp(v, !w)));
			}

		cout << ansv.size() << endl;
		for(i = 0; i < ansv.size(); i++) cout << ansv[i].f << " " << ansv[i].s.f << " " << ansv[i].s.s << endl;

		return 0;
	}