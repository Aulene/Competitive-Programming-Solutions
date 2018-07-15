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

vector < pair <int, int> > chef[1007], feh[1007];
int dist1[1007], dist2[1007];

priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

int dijkstras(int src)
{
	for(int i = 0; i < 1007; i++) dist1[i] = dist2[i] = INT_MAX;
	dist1[src] = dist2[src] = 0;
	
	pq.p(mp(src, dist1[src]));

	pair <int, int> pz, nx;

	while(!pq.empty())
		{
			pz = pq.top();
			pq.pop();

			int u = pz.f, v = pz.s;

			for(int i = 0; i < chef[u].size(); i++)
				{
					nx = chef[u][i];

					if(dist1[nx.f] > nx.s + v)
						{
							dist1[nx.f] = nx.s + v;
							pq.p(mp(nx.f, dist1[nx.f]));
						}
				}
		}

	pq.p(mp(src, dist2[src]));

	while(!pq.empty())
		{
			pz = pq.top();
			pq.pop();

			int u = pz.f, v = pz.s;

			for(int i = 0; i < feh[u].size(); i++)
				{
					nx = feh[u][i];

					if(dist2[nx.f] > nx.s + v)
						{
							dist2[nx.f] = nx.s + v;
							pq.p(mp(nx.f, dist2[nx.f]));
						}
				}
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, n, i, j, u, v, w;

		cin >> t;

		while(t--)
			{
				for(i = 0; i < 1007; i++)
					chef[i].clear(), feh[i].clear();

				int ans = 0;

				cin >> n;

				for(i = 0; i < n - 1; i++)
					{
						cin >> u >> v >> w;
						chef[u].pb(mp(v, w)), chef[v].pb(mp(u, w));
					}

				for(i = 0; i < n - 1; i++)
					{
						cin >> u >> v >> w;
						feh[u].pb(mp(v, w)), feh[v].pb(mp(u, w));
					}

				for(i = 1; i <= n; i++)
					{
						dijkstras(i);
						for(j = i; j <= n; j++)
							ans += min(dist1[j], dist2[j]);

						// cout << "OPEN " << i << endl;
						// for(j = i; j <= n; j++)
						// 	cout << dist1[j] << " ";
						// cout << endl;
						// for(j = i; j <= n; j++)
						// 	cout << dist2[j] << " ";
						// cout << "CLOSE\n";
					}

				cout << ans << endl;
			}
		return 0;
	}