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

int r, c;
int a[107][107];
int dp[107][107];

int recur(int x, int y)
{
	if(y<0 || y>=c)
		return -100001;

	if(x>=r)
		return 0;

	if(dp[x][y]!=-1)
		return dp[x][y];

	int ans1, ans2, ans3, ans;
	ans1=recur(x+1, y-1);
	ans2=recur(x+1, y);
	ans3=recur(x+1, y+1);

	ans=max(ans1, ans2);
	ans=max(ans, ans3);

	return dp[x][y]=a[x][y]+ans;
}

int main()
	{
		int t, i, j;
		int ans;

		cin >> t;

		while(t--)
			{
				ans=0;

				cin >> r >> c;

				for(i=0; i<107; i++)
					for(j=0; j<107; j++)
						dp[i][j]=-1;

				for(i=0; i<r; i++)
					for(j=0; j<c; j++)
						cin >> a[i][j];

				for(i=0; i<c; i++)
					ans=max(ans, recur(0, i));
				
				cout << ans << endl;
			}

		return 0;
	}