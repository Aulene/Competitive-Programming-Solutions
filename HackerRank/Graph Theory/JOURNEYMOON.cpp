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

vector<lli> g[100007];
bool visited[100007];
vector<lli> a;

lli dfs(int index)
{
	if(visited[index])
		return 0;

	visited[index]=1;

	vector<lli>::iterator it;
	lli ans=1;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		ans+=dfs(*it);

	return ans;
}

int main()
	{
		lli n, k, i, u, v;
		lli num, ans;
		vector<lli>::iterator it;

		cin >> n >> k;

		ans=n*(n-1)/2;

		while(k--)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i=1; i<=n; i++)
			if(!visited[i])
				{
					num=dfs(i);
					a.pb(num);
				}

		for(it=a.begin(); it!=a.end(); it++)
			{
				num=*it;
				num=num*(num-1);
				num/=2;
				ans-=num;
			}

		cout << ans << endl;
		return 0;
	}