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

bool g[1007][1007];
lli a[1007];
lli n;
lli parent[1007];
bool visited[1007];

lli getsum(lli index)
{
	lli ans, i;

	visited[index]=1;

	for(i=1; i<=n; i++)
		if(g[index][i] && !visited[i])
			ans+=getsum(i);

	return ans+a[index];
}

lli addval(lli index, lli val)
{
	lli i;

	a[index]+=val;

	for(i=1; i<=n; i++)
		if(g[index][i])
			addval(i, val);
	return 0;
}
int main()
	{
		lli f, q, i, j, x;
		lli u, v;

		cin >> n >> f;

		for(i=1; i<=n; i++)
			cin >> a[i];

		for(i=0; i<n-1; i++)
			{
				cin >> u >> v;
				g[u][v]=1;
				parent[v]=u;
			}

		while(f--)
			{
				cin >> q;
				memset(visited, 0, sizeof(visited));
				if(q==1)
					{
						cin >> u;
						lli ans=getsum(u);
						cout << ans << endl;
					}
				else if(q==2)
					{
						cin >> u >> v;
						addval(u, v);
					}
				else if(q==3)
					{
						cin >> u >> v;
						x=parent[u];
						g[x][u]=0;
						g[x][v]=1;
						parent[u]=parent[v];
						parent[v]=x;
						g[parent[u]][v]=0;
						g[parent[u]][u]=1;
					}
			}

		return 0;
	}