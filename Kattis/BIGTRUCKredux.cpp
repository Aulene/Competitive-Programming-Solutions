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

int a[107];
vector < pair <int, int> > g[107];
int src[107], dist[107];
priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

int dijkstras(int n)
{
	for(int i = 1; i <= n; i++) dist[i] = 100007, src[i] = 100007;
	dist[1] = 0;
	src[1] = a[1];

	int u, v, w, vw;
	pair <int, int> pz, nz;

	pq.p(mp(1, dist[1]));

	while(!pq.empty())
		{
			pz = pq.top();
			pq.pop();
			u = pz.f, w = pz.s;
			
			for(int i = 0; i < g[u].size(); i++)
				{
					nz = g[u][i];

					v = nz.f, vw = nz.s;

					if(dist[v] > vw + w)
						{
							dist[v] = vw + w;
							src[v] = src[u] + a[v];
							pq.p(mp(v, dist[v]));
						}
					else if(dist[v] == vw + w && src[v] < src[u] + a[v])
						{
							src[v] = src[u] + a[v];
							pq.p(mp(v, dist[v]));
						}
				}
		}

	return n;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		cin >> m;

		while(m--)
			{
				cin >> u >> v >> w;
				g[u].pb(mp(v, w));
				g[v].pb(mp(u, w));
			}

		int ans = dijkstras(n);
		
		if(dist[ans] < 100007) cout << dist[ans] << " " << src[ans] << endl;
		else cout << "impossible" << endl;
		return 0;
	}