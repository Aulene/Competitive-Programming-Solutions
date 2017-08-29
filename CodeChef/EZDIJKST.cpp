#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<set>
#include<list>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair

vector< pair<int, int> > g[100007];
priority_queue < pair < int, int > , vector < pair < int, int > > , greater < pair < int, int > > > pq;
int dist[100007];
int n;

int dijkstra(int start, int reach)
{
	int v, d, i;
	vector< pair < int, int > >::iterator it;

	for(i=0; i<=n; i++)
		dist[i]=INT_MAX;
	dist[start]=0;

	pq.p(mp(start, dist[start]));

	while(!pq.empty())
		{
			v=pq.top().first;
			d=pq.top().second;

			pq.pop();

			for(it=g[v].begin(); it!=g[v].end(); it++)
				if(dist[it->first] > d+it->second)
					{
						dist[it->first]=d+it->second;
						pq.p(mp(it->first, dist[it->first]));
					}
		}

	return dist[reach];
}

int main()
	{
		int t, m, i, u, v, wt;
		int x, y, ans;

		cin >> t;

		while(t--)
			{
				cin >> n >> m;

				while(m--)
					{
						cin >> u >> v >> wt;
						g[u].pb(mp(v, wt));
					}

				cin >> x >> y;
			
				ans=dijkstra(x, y);

				if(ans==INT_MAX)
					cout << "NO" << endl;
				else
					cout << ans << endl;

				for(i=0; i<=n; i++)
					g[i].clear();
			}

		return 0;
	}