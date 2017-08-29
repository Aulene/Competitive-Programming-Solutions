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
#define pb push_back

int a[307];
lli dp[307][307];
lli n;

lli recur(int index, lli m)
{
	if(m<0)
		return 0;

	if(index>=n)
		return 0;

	if(dp[index][m]!=-1)
		return dp[index][m];

	if(m==0)
		return 1;

	lli ans1=0, ans2=0, ans, i;

	ans1=recur(index+1, m);
	ans2=recur(index, m-a[index]);

	return dp[index][m]=ans1+ans2;
}

int main()
	{
		lli m, i;
		lli ans, j;

		cin >> m >> n;

		for(i=0; i<n; i++)
			cin >> a[i];

		for(i=0; i<307; i++)
			for(j=0; j<307; j++)
				dp[i][j]=-1;

		ans=recur(0, m);

		cout << ans << endl;

		return 0;
	}