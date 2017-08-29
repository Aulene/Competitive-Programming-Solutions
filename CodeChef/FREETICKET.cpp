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

lli g[237][237];

int main()
	{
		lli n, m, i, j, k, u, v;
		lli wt, ans=0;

		cin >> n >> m;

		for(i=0; i<237; i++)
			for(j=0; j<237; j++)
				if(i!=j)
					g[i][j]=INT_MAX;
		while(m--)	
			{
				cin >> u >> v >> wt;
				g[u][v]=wt;
				g[v][u]=wt;
			}

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				for(k=1; k<=n; k++)
					g[j][k]=min(g[j][k], g[j][i]+g[i][k]);

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				if(i!=j)
					ans=max(ans, g[i][j]);

		cout << ans << endl;
		return 0;
	}