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

bool g[47][47];
bool vis[47];
lli dp[47];
lli final, n;

lli dfs(lli index, lli num)
{
	if(num < dp[index])
		{
			dp[index]=num;
			lli ans=10007, i;

			for(i=1; i<=n; i++)
				if(g[i][index])
					dfs(i, num+1);
		}
	
	return 0;
}

int main()
	{
		lli t, i, j, k, a, b, num;

		cin >> t;

		while(t--)
			{
				for(i=0; i<47; i++)
					for(j=0; j<47; j++)
						g[i][j]=0;

				lli ans=0;

				for(i=0; i<47; i++)
					vis[i]=0;

				cin >> n;

				for(i=1; i<n; i++)
					{
						g[i][i+1]=1;
						g[i+1][i]=1;
					}

				cin >> k;

				while(k--)
					{
						cin >> a >> b;
						g[a][b]=1;
						g[b][a]=1;
					}

				for(i=1; i<=n; i++)
					{
						for(j=0; j<47; j++)
							dp[j]=10007;

						dfs(i, 0);

						for(j=i; j<=n; j++)
							{
								//cout << dp[j] << " ";
								ans=ans+dp[j];
							}
						cout << endl;
					}

				cout << ans << endl;
			}

		return 0;
	}