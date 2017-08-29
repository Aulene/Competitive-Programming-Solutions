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

lli a[2507][2507];
lli dp1[2507][2507], dp2[2507][2507];
int n;

lli recur1(int x, int y)
{
	if(x<1 || x>n || y<1 || y>n)
		return -100000007;
	
	if(x==n && y==n)
		return dp1[x][y]=a[x][y];

	if(dp1[x][y]!=-1)
		return dp1[x][y];

	lli ans1=0, ans2=0, ans;
	ans1=recur1(x+1, y);
	ans2=recur1(x, y+1);
	ans=max(ans1, ans2);

	return dp1[x][y]=a[x][y]+ans;
}

lli recur2(int x, int y)
{
	if(x<1 || x>n || y<1 || y>n)
		return -100000007;

	if(x==n && y==1)
		return dp2[x][y]=a[x][y];

	if(dp2[x][y]!=-1)
		return dp2[x][y];

	lli ans1=0, ans2=0, ans;
	ans1=recur2(x, y-1);
	ans2=recur2(x+1, y);
	ans=max(ans1, ans2);

	return dp2[x][y]=a[x][y]+ans;
}

int main()
	{
		int i, j;
		lli ans=-1000000007;

		cin >> n;

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				cin >> a[i][j];

		for(i=0; i<2507; i++)
			for(j=0; j<2507; j++)
				{
					dp1[i][j]=-1;
					dp2[i][j]=-1;
				}

		recur1(1, 1);
		recur2(1, n);

		
		cout << endl << endl;

		for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
					cout << dp1[i][j] << " ";
				cout << endl;
			}

		cout << endl << endl;

		for(i=1; i<=n; i++)
			{
				for(j=1; j<=n; j++)
					cout << dp2[i][j] << " ";
				cout << endl;
			}
		

		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
				{
					ans=max(ans, dp1[i][j+1]+dp2[i-1][j]);
					ans=max(ans, dp1[i+1][j]+dp2[i][j+1]);
				}
		
		cout << ans << endl;
		return 0;
	}