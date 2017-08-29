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

vector <int> a[100007];
int dp[100007][2];

int dfs(int index, int parent, bool cov)
{
	if(dp[index][cov]!=-1)
		return dp[index][cov];

	int ans1=0, ans2=1, ans, u;
	vector<int>::iterator it;

	if(cov)
		{
			for(it=a[index].begin(); it!=a[index].end(); it++)
				{
					u=*it;

					if(u!=parent)
						ans1+=dfs(u, index, false);
				} 

			for(it=a[index].begin(); it!=a[index].end(); it++)
				{
					u=*it;

					if(u!=parent)
						ans2+=dfs(u, index, true);
				}

			ans=min(ans1, ans2);
		}	
	else
		{
			for(it=a[index].begin(); it!=a[index].end(); it++)
				{
					u=*it;

					if(u!=parent)
						ans2+=dfs(u, index, true);
				}
			ans=ans2;
		}

	return dp[index][cov]=ans;
}

int main()
	{
		int n, i, u, v, j;
		int ans1=1, ans2=0	, ans;
		vector<int>::iterator it;

		cin >> n;

		for(i=0; i<n-1; i++)
			{
				cin >> u >> v;
				a[u].pb(v);
				a[v].pb(u);
			}

		memset(dp, -1, sizeof(dp));

		for(it=a[1].begin(); it!=a[1].end(); it++)
			{
				u=*it;
				ans1+=dfs(u, 1, true);
			}

		for(it=a[1].begin(); it!=a[1].end(); it++)
			{
				u=*it;
				ans2+=dfs(u, 1, false);
			}

		ans=min(ans1, ans2);
		cout << ans << endl;

		return 0;
	}