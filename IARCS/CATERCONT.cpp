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

lli a[100007];
vector <int> g[100007];
lli dp[100007][7];

lli dfs(int index, int parent, bool choseParent)
{
	if(dp[index][choseParent]!=-1)
		return dp[index][choseParent];

	lli ans=0, ans1=a[index], ans2=0, i, v;
	vector<int>::iterator it;

	if(!choseParent)
		{
			for(it=g[index].begin(); it!=g[index].end(); it++)
				{
					v=*it;

					if(v!=parent)
						{
							ans1+=dfs(v, index, 1);
							ans2+=dfs(v, index, 0);
						}
				}

			ans=max(ans1, ans2);
		}
	else
		{
			for(it=g[index].begin(); it!=g[index].end(); it++)
				{
					v=*it;

					if(v!=parent)
						ans+=dfs(v, index, 0);
				}
		}

	return dp[index][choseParent]=ans;
}
	
int main()
	{
		int n, i, u, v, j;
		lli ans;

		cin >> n;

		for(i=0; i<100007; i++)
			for(j=0; j<7; j++)
				dp[i][j]=-1;

		for(i=1; i<=n; i++)
			cin >> a[i];

		for(i=0; i<n-1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		ans=max(dfs(1, -1, 0), dfs(1, -1, 1));
		cout << ans << endl;
		return 0;
	}