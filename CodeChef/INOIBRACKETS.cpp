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

lli a[707];
lli v[707];
lli dp[707][707];
lli k;

lli recur(int l, int r)
{
	if(r<=l)
		return 0;

	if(dp[l][r]!=-100000007)
		return dp[l][r];

	int i, j;
	lli ans=-100000007;

	for(i=l+1; i<=r; i++)
		if(a[i] == a[l]+k)
			{
				ans=max(ans, v[l]+v[i]+recur(l+1, i-1)+recur(i+1, r));
			}

	ans=max(ans, recur(l+1, r));
	
	return dp[l][r]=ans;
}

int main()
	{
		lli n, i, j;
		lli ans=0;

		for(i=0; i<707; i++)
			for(j=0; j<707; j++)
				dp[i][j]=-100000007;

		cin >> n >> k;

		for(i=0; i<n; i++)
			cin >> v[i];

		for(i=0; i<n; i++)
			cin >> a[i];
		
		ans=recur(0, n-1);

		/*
		for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
					cout << dp[i][j] << " ";
				cout << endl;
			}
		*/

		cout << ans << endl;

		return 0;
	}