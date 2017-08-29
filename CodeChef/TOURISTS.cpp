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

lli n;			
vector <lli> g[200007];
vector < pair <lli, lli> > q;
map < lli, lli > mainAns[200007];
lli deg[200007];
bool vis[200007];
map <lli, bool> erased[200007];

lli dfs(lli index)
{
	lli i, v=index, u;
	vector <lli>::iterator it;
	
	for(it=g[v].begin(); it!=g[v].end(); it++)
		if(!erased[*it][index])
			{
				u=*it;
				erased[u][v]=erased[v][u]=1;
				mainAns[u][v]=1;
				mainAns[v][u]=2;
				dfs(u);
			}

	return 0;
}

lli connectedDfs(lli index)
{
	if(vis[index])
		return 0;

	vis[index]=1;

	vector <lli>::iterator it;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		if(!vis[*it])
			connectedDfs(*it);

	return 0;
}

int main()
	{
		lli e, u, v, i, stv;
		bool ans=1;
		vector < pair <lli, lli> >::iterator it;

		scanf("%lld %lld", &n, &e);

		while(e--)
			{
				scanf("%lld %lld", &u, &v);
				g[u].pb(v);
				g[v].pb(u);
				q.pb(mp(u, v));
				deg[u]++;
				deg[v]++;
			}

		connectedDfs(1);

		for(i=1; i<=n; i++)
			if(deg[i]%2 || !vis[i])
				{
					ans=0;
					break;
				}
				
		if(!ans)
			printf("NO\n");
		else
			{
				printf("YES\n");
				dfs(1);

				for(it=q.begin(); it!=q.end(); it++)
					{
						u=it->first, v=it->second;
						if(mainAns[u][v]==2)
							{
								//cout << "1" << endl;
								printf("%lld %lld\n", u, v);
							}
						else
							{
								//cout << "2" << endl;
								printf("%lld %lld\n", v, u);
							}
					}
			}

		return 0;
	}