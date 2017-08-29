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

int g[1007][1007];
int nodesVisited, extraEdges;
bool vis[1007];
bool edgeVis[1007][1007];

int ans=0;
int n;

int dfs(int index)
{
	if(vis[index])
		return 0;

	vis[index]=1;
	nodesVisited++;

	int i;

	for(i=1; i<=n; i++)
		if(!edgeVis[index][i] && g[index][i])
			{
				edgeVis[index][i]=edgeVis[i][index]=1;
				extraEdges++;
				dfs(i);
			}

	return 0;
}

int main()
	{
		int i, j;
		int totalEdges, c=0, num, ans=0;

		cin >> n;

		totalEdges=n-1;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				cin >> g[i][j];

		for(i=1; i<=n; i++)
			if(!vis[i])
				{
					nodesVisited=extraEdges=0;
					dfs(i);
					totalEdges=nodesVisited-1;
					ans=ans+abs(totalEdges-extraEdges);
				}

		cout << ans << endl;
		return 0;
	}