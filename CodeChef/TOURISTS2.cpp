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

list <lli> g[200007];
stack <lli> temp, final;
lli n;

int rem(int u, int v)
{
	list<lli>::iterator it;

	it=find(g.begin(), g.end(), v);
	*it=0;
	it=find(v.begin(), v.end(), u);
	*it=0;

	return 0;
}

bool bridge(int u, int v)
{
	int c=0, x;
	list<lli>::iterator it;

	for(it=g[u].begin(); it!=g[u].end(); it++)
		if(*it)
			c++;

	if(c==1)
		return 1;

	bool vis[100007];
	
}

lli dfs(int index)
{
	lli i, u, v;
	list<lli>::iterator it, it1;
	
	memset(vis, 0, sizeof(vis));

	for(it=g[index].begin(); it!=g[index].end(); it++)
		{
			v=*it;

			if(v && bridge(u, v))
				{
					cout << u << " " << v << endl;
					rem(u, v);
					dfs(v);
				}
		}
	return 0;
}

lli connectedDfs(int index)
{
	if(vis[index])
		return 0;

	vis[index]=1;

	vector <lli>::iterator it;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		connectedDfs(*it);

	return 0;
}

int main()
	{
		lli e, u, v, i, stv;
		bool ans=1, oddenc=0;

		cin >> n >> e;

		while(e--)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
				deg[u]++;
				deg[v]++;
			}

		for(i=1; i<=n; i++)
			if(deg[i]%2)
				ans=0;

		connectedDfs(1);

		for(i=1; i<=n; i++)
			if(!vis[i])
				ans=0;


		if(!ans)
			cout << "NO" << endl;
		else
			{
				cout << "YES" << endl;
				dfs();
			}

		return 0;
	}