#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<algorithm>
#include<vector>
#include<unordered_map>
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

unordered_map <string, int> m;
vector < pair <int, int > > g[200007];
priority_queue < pair <int, int>, vector < pair < int, int > >, greater < pair < int, int > > > pq;
int dist[200007];
int n;

int dijkstra(int start, int reach)
{
	int i, v, d;
	vector< pair <int, int > >::iterator it;

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
		int t, i, j, u, wt, q;
		int e;
		string s1, s2, s;

		scanf("%d", &t);

		while(t--)
			{
				scanf("%d", &n);

				for(i=1; i<=n; i++)
					{
						cin >> s;
						m[s]=i;
						scanf("%d", &e);

						while(e--)
							{
								scanf("%d %d", &u, &wt);
								g[i].pb(mp(u, wt));
							}
					}

				scanf("%d", &q);
				while(q--)
					{
						cin >> s1 >> s2;
						printf("%d\n", dijkstra(m[s1], m[s2]));
					}
			}

		return 0;
	}