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
#define pb push_back

vector<int> g[1000007];

int endNode1, endNode2;
int ans=-1;

int dfs1(int index)
{
	if(index==endNode1)
		{
			ans=1;
			return 0;
		}

	vector<int>::iterator it;
	int u;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		{
			u=*it;
			dfs1(u);
		}

	return 0;
}

int dfs2(int index)
{
	if(index==endNode2)
		{
			ans=0;
			return 0;
		}

	vector<int>::iterator it;
	int u;

	for(it=g[index].begin(); it!=g[index].end(); it++)
		{
			u=*it;
			dfs2(u);
		}

	return 0;
}

int main()
	{
		int n, m, i, u, v;

		cin >> n >> m;

		while(m--)
			{
				cin >> u >> v;
				g[u].pb(v);
			}

		cin >> u >> v;
		endNode1=v;
		endNode2=u;
		
		dfs1(u);
		dfs2(v);

		if(ans==-1)
			cout << "unknown" << endl;
		else if(ans==1)
			cout << "yes" << endl;
		else
			cout << "no" << endl;	
		return 0;
	}