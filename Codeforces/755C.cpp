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

vector <int> g[100007];
bool vis[100007];

int dfs(int index)
{
	if(vis[index])
		return 0;

	vis[index]=1;

	int u, v, i, ans;
	vector<int>::iterator it;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		dfs(*it);
	return 0;
}

int main()
	{
		int n, m, i, j, u, v;
		int ans=0;

		cin >> n;

		for(i=1; i<=n; i++)
			{
				cin >> u;
				v=i;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i=1; i<=n; i++)
			if(!vis[i])
				ans=ans+1+dfs(i);

		cout << ans << endl;
		return 0;
	}