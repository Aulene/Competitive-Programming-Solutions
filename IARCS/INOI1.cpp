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

map < lli, bool > m[1000007];
map < lli, bool > vis[1000007];
vector < pair < lli, lli > > p;

lli dfs(lli x, lli y)
{
	if(!m[x][y])
		return 1;

	if(vis[x][y])
		return 0;

	lli ans=0;

	if(m[x][y])
		{
			vis[x][y]=1;
			ans=dfs(x-1, y)+dfs(x+1, y)+dfs(x, y-1)+dfs(x, y+1);
		}

	return ans;
}

int main()
	{
		lli r, c, n, i, j, u, v;
		lli ans=0;
		vector < pair < lli, lli > >::iterator it;

		cin >> r >> c >> n;

		for(i=0; i<n; i++)
			{
				cin >> u >> v;
				m[u][v]=1;
				p.pb(mp(u, v));
			}

		for(it=p.begin(); it!=p.end(); it++)
			if(!vis[it->first][it->second])
				{
					ans=max(ans, dfs(it->first, it->second));
				}

		cout << ans << endl;
		return 0;
	}