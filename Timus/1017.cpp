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

lli dp[507][507];

lli recur(int bricks, int prev)
{
	if(bricks==0)
		return 1;

	if(bricks<=prev || bricks<0)
		return 0;

	if(dp[bricks][prev]!=-1)
		return dp[bricks][prev];

	lli ans=0, i;

	for(i=prev+1; i<=bricks; i++)
		ans+=recur(bricks-i, i);

	return dp[bricks][prev]=ans;
}

int main()
	{
		int n, i, j, k;
		lli ans=0;

		cin >> n;

		for(i=0; i<507; i++)
			for(j=0; j<507; j++)
				dp[i][j]=-1;

		for(i=1; i<=n; i++)
			if(n-i > i)
				ans+=recur(n-i, i);
		cout << ans << endl;

		return 0;
	}