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

char a[207][207];
int n, m;
int dp[207][207];

int recur(int x, int y, int face)
{
	if(x<1 || x>n || y<1 || y>m)
		return 0;

	if(dp[x][y]!=-1)
		return dp[x][y];

	if(a[x][y]=='#')
		return -100001;

	int ans1, ans2, ans;
	
	if(face==1)
		{
			ans1=recur(x, y+1, face);
			ans2=recur(x+1, y, 2);
		}
	else
		{
			ans1=recur(x, y-1, face);
			ans2=recur(x+1, y, 1);
		}

	ans=max(ans1, ans2);

	if(a[x][y]=='T')
		return dp[x][y]=1+ans;
	else
		return dp[x][y]=ans;
}

int main()
	{
		int t, i, j;

		cin >> t;

		while(t--)
			{
				for(i=0; i<207; i++)
					for(j=0; j<207; j++)
						dp[i][j]=-1;

				cin >> n >> m;

				for(i=1; i<=n; i++)
					for(j=1; j<=m; j++)
						cin >> a[i][j];

				int ans;
				ans=recur(1, 1, 1);

				if(ans<0)
					ans=0;
				cout << ans << endl;
			}
		return 0;
	}




























































