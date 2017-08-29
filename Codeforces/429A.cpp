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

vector<int> g[100007];
int in[100007];
int goal[100007];
int dp[100007][2];

int dfs(int index, bool parentFlip)
{
	if(dp[index][parentFlip]!=-1)
		return dp[index][parentFlip];

	int i, v, ans1=0, ans2=1, ans;
	vector<int>::iterator it;

	if(!parentFlip)
		{
			for(it=a[index].begin(); it!=a[index].end(); it++)
				
		}
}

int main()
	{
		int n, u, v, i;

		cin >> n;

		for(i=0; i<n; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
			}

		for(i=0; i<n; i++)
			cin >> in[i];

		for(i=0; i<n; i++)
			cin >> goal[i];

		return 0;
	}