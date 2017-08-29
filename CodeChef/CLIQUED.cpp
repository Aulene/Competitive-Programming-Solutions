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
 
vector< pair< lli, lli > > g[100007];
priority_queue< pair <lli, lli >, vector < pair <lli, lli > >, greater < pair <lli, lli > > > pq;
lli dist[100007];
 
lli t, n, i, j;
lli k, x, m, s;
lli a, b, c;
 
lli dijkstra(lli start)
{
	lli i, v, d;
	vector< pair <lli, lli> >::iterator it;
 	bool cliqEnc=0;
 
	for(i=0; i<100007; i++)
		dist[i]=100000000007;
	dist[start]=0;
 
	pq.p(mp(start, dist[start]));
 
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
 
						if(it->first <= k)
							{
								for(i=1; i<=k; i++)
									if(i != it->first)
										{
											if(min(dist[i], dist[it->first]+x) == dist[it->first]+x)
												{
													dist[i] = min(dist[i], dist[it->first]+x);
													pq.p(mp(i, dist[i]));
												}
										}
 
							}
					}
		}
 
	return 0;
}
 
int main()
	{
		cin >> t;
 
		while(t--)
			{
				cin >> n >> k >> x >> m >> s;
 
				for(i=1; i<=k; i++)
					for(j=1; j<=k; j++)
						{
							g[i].pb(mp(j, x));
							g[j].pb(mp(i, x));
						}
 
				for(i=0; i<m; i++)
					{
						cin >> a >> b >> c;
						g[a].pb(mp(b, c));
						g[b].pb(mp(a, c));
					}	
 
				dijkstra(s);
 
				for(i=1; i<=n; i++)
					cout << dist[i] << " ";
				cout << endl;
 
				for(i=1; i<=n; i++)
					g[i].clear();
			}
		return 0;
	}  