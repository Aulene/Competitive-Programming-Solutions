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

char a[27][27];
bool visited[27][27];
int ans;
int n, m;

int dfs(int x, int y)
{
	if(visited[x][y] || a[x][y]=='#' || x<0 || x>=n || y<0 || y>=m)
		return 0;

	visited[x][y]=1;
	ans++;

	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);

	return 0;
}

int main()
	{
		int t, i, j, k;
		int rootx, rooty;
		cin >> t;

		for(k=1; k<=t; k++)
			{
				ans=0;

				cin >> m >> n;

				for(i=0; i<n; i++)
					for(j=0; j<m; j++)
						{
							cin >> a[i][j];

							if(a[i][j]=='@')
								{
									rootx=i;
									rooty=j;
								}
						}

				dfs(rootx, rooty);
				printf("Case %d: %d\n", k, ans); 

				for(i=0; i<27; i++)
					for(j=0; j<27; j++)
						visited[i][j]=0;
			}

		return 0;
	}