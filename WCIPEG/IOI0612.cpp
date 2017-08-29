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
int dp[1007][1007];

int recur(int x, int y)
{
	if(dp[x][y]!=-1)
		return dp[x][y];

	return dp[x][y]=g[x][y]+recur(x-1, y)+recur(x, y-1)-recur(x-1, y-1);
}

int main()
	{
		int n, m, a, b, c, d;
		int i, j;
		int ans1X, ans1Y, ans2X, ans2Y;
		int elevation, maxEl=0;
		
		cin >> m >> n >> a >> b >> c >> d;

		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
				cin >> g[i][j];

		for(i=1; i<1007; i++)
			for(j=1; j<1007; j++)
				dp[i][j]=-1;

		recur(n, m); //isko mat chuhiyo

		return 0;
	}