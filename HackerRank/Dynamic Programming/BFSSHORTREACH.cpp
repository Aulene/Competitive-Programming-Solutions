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
#define pb push_back
#define mp make_pair
#define p push

vector< pair <int, int> > a[1007];
queue<int> q;
int dist[1007];
bool visited[1007];
int n;

int bfs(int index)
{
	int i, v;
	int x, y;

	vector< pair <int, int> >::iterator it;

	for(i=0; i<=n; i++)
		{
			dist[i]=INT_MAX;
			visited[i]=0;
		}

	dist[index]=0;
	visited[index]=1;
	q.p(index);

	while(!q.empty())
		{
			v=q.front();
			q.pop();

			for(it=a[v].begin(); it!=a[v].end(); it++)
				{
					x=it->first;

					if(!visited[x])
						{
							visited[x]=1;
							q.p(x);
						}

					dist[x]=min(dist[x], dist[v]+it->second);
				}
		}

	return 0;
}

int main()
	{
		int q, m, i, u, v, s;

		cin >> q;

		while(q--)
			{
				cin >> n >> m;

				while(m--)
					{
						cin >> u >> v;
						a[u].pb(mp(v, 6));
						a[v].pb(mp(u, 6));
					}

				cin >> s;
				bfs(s);

				for(i=1; i<=n; i++)
					if(i!=s)
						{
							if(dist[i]!=INT_MAX)
								cout << dist[i] << " ";
							else
								cout << "-1 ";
						}
				cout << endl;

				for(i=1; i<=n; i++)
					a[i].clear();
			}

		return 0;
	}