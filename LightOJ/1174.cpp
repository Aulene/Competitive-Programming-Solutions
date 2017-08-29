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

int g[107][107];

int main()
	{
		int t, n, u, v, i, j, k, r, x;
		int ans, src, dest;

		cin >> t;

		for(x=1; x<=t; x++)
			{
				ans=0;

				cin >> n >> r;

				for(i=0; i<107; i++)
					for(j=0; j<107; j++)
						g[i][j]=500000;

				for(i=0; i<107; i++)
					g[i][i]=0;

				while(r--)
					{
						cin >> u >> v;
						g[u][v]=1;
						g[v][u]=1;
					}

				cin >> src >> dest;

				for(i=0; i<n; i++)
					for(j=0; j<n; j++)
						for(k=0; k<n; k++)
							g[j][k]=min(g[j][k], g[i][j]+g[i][k]);

				for(i=0; i<n; i++)
					ans=max(ans, g[src][i]+g[i][dest]);
				
				printf("Case %d: %d\n", x, ans);
			}

		return 0;
	}