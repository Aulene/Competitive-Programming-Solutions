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

bool hasHospital[100007];
lli dist[100007];
vector < pair < lli, lli > > g[100007];
priority_queue< pair <lli, lli>, vector < pair <lli, lli> >, greater < pair <lli, lli> > > pq;
lli n, m, p;

lli dijkstra()
{
	lli i, v, d;
	vector< pair <lli, lli> >::iterator it;

	for(i=0; i<100007; i++)
		{
			if(hasHospital[i])
				dist[i]=0;
			else
				dist[i]=10000000007;
		}

	for(i=1; i<=n; i++)
		{
			if(hasHospital[i])
				{
					pq.p(mp(i, dist[i]));

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
		}

	return 0;
}

int main()
	{
		lli x, y, d;
		lli i, j;

		cin >> n >> m >> p;

		for(i=1; i<=p; i++)
			{
				cin >> x;
				hasHospital[x]=1;
			}

		while(m--)
			{
				cin >> x >> y >> d;
				g[x].pb(mp(y, d));
				g[y].pb(mp(x, d));
			}

		dijkstra();

		for(i=1; i<=n; i++)
			{
				if(!hasHospital[i])
					{
						if(dist[i]!=10000000007)
							cout << i << " " << dist[i] << endl;
						else
							cout << i << " " << "-1" << endl;
					}
			}

		return 0;
			
	}