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

vector<int> g[107];
queue<int> q;
int mode[107], dist[107];
bool vis[107];

int bfs(int start)
{
	int i, v, x;

	vis[start]=1;
	q.p(start);
	dist[start]=0;

	while(!q.empty())
		{
			v=q.front();
			q.pop();

			for(i=1; i<=6; i++)
				{
					x=mode[v+i];

					if(x>=1 && x<=100 && !vis[x])
						{
							q.p(x);
							vis[x]=1;
							dist[x]=dist[v]+1;
						}
				}
		}

	if(!vis[100])
		return -1;
	else
		return dist[100];
}

int main()
	{
		int t, n, u, v, i, j, m;

		cin >> t;

		while(t--)
			{
				for(i=0; i<107; i++)
					{
						g[i].clear();
						mode[i]=i;
						vis[i]=0;
					}

				cin >> n;

				for(i=0; i<n; i++)
					{
						cin >> u >> v;
						mode[u]=v;
					}

				cin >> m;

				for(i=0; i<m; i++)
					{
						cin >> u >> v;
						mode[u]=v;
					}

				cout << bfs(1) << endl;
			}

		return 0;
	}