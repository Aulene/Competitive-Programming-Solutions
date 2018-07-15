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

bool a[100007];
int dist[100007];
int ans = 1000000000007;
vector <int> s;
vector < pair <int, int> > g[100007];
priority_queue < pair <int, int> , vector < pair <int, int> > , greater < pair <int, int> > > pq;

void dijkstras(int src)
{
	int i, j, u, v, x, y;

	for(i = 0; i < 100007; i++) dist[i] = 1000000000007;
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

		int n, m, k, i, j, u, v, w;

		cin >> n >> m >> k;

		for(i = 0; i < k; i++)
			cin >> u, a[u] = 1, s.pb(u);

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> w;
				g[u].pb(mp(v, w)); g[v].pb(mp(u, w));
			}

		for(i = 0; i < s.size(); i++)
			dijkstras(s[i]);

		cout << ans << endl;

		return 0;
	}