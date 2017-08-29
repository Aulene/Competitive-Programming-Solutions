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
#define mod 1000000000
#define p push
#define pb push_back
#define mp make_pair

vector<lli> g[100007];
bool vis1[10007], vis2[10007], vis[10007];
lli dp[10007];
lli n;

bool cycleDfs(int index)
{
	if(!vis1[index])
		{
			vis1[index]=1;
			vis2[index]=1;

			vector<lli>::iterator it;
			for(it=g[index].begin(); it!=g[index].end(); it++)
				{
					if(!vis1[*it] && cycleDfs(*it))
						return 1;
					if(vis2[*it])
						return 1;
				}
		}

	vis2[index]=0;
	return 0;
}

int connected(int index)
{
	if(vis[index])
		return 0;

	if(index==2)
		return 1;

	vis[index]=1;

	vector<lli>::iterator it;
	int ans=0;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		ans=max(ans, connected(*it));

	return ans;
}

lli dfs(int index)
{
	if(dp[index]!=-1)
		return dp[index];

	lli ans=0;
	vector<lli>::iterator it;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		ans=(ans+dfs(*it))%mod;

	return dp[index]=ans;
}

int main()
	{
		lli m, i, u, v;
		lli ans;

		memset(dp, -1, sizeof(dp));
		dp[2]=1;

		cin >> n >> m;

		while(m--)
			{
				cin >> u >> v;
				g[u].pb(v);
			}

		if(!connected(1))
			{
				cout << "0" << endl;
				return 0;
			}

		if(cycleDfs(1))
			{
				cout << "inf" << endl;
				return 0;
			}

		ans=dfs(1);
		cout << ans << endl;

		return 0;
	}