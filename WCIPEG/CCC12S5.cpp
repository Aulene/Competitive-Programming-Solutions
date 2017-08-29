#include<iostream>
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

lli r, c;
bool grid[37][37];
int dp[37][37];

lli recur(lli x, lli y)
{
	if(dp[x][y]>=0)
		return dp[x][y];

	if(grid[x][y])
		return 0;

	//cout << x << " " << y << endl;
	
	lli ans1=0, ans2=0, ans;

	if(x<r)
		ans1=recur(x+1, y);
	if(y<c)
		ans2=recur(x, y+1);

	ans=ans1+ans2;
	return dp[x][y]=ans;
}

int main()
	{
		lli n, u, v, i, j;
		lli ans;

		cin >> r >> c >> n;

		for(i=0; i<37; i++)
			for(j=0; j<37; j++)
				dp[i][j]=-1;
		dp[r][c]=1;

		while(n--)
			{
				scanf("%lld %lld", &u, &v);
				grid[u][v]=1;
			}

		ans=recur(1, 1);
		cout << ans << endl;

		return 0;
	}