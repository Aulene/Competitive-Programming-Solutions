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

int a[3007];
int dp1[3007], dp2[3007];
int n;

int recur1(int index)
{
	if(index>n)
		return 0;

	if(dp1[index]!=-10000007)
		return dp1[index];

	int ans;
	ans=max(recur1(index+1), recur1(index+2));
	return dp1[index]=ans+a[index];
}

int recur2(int index)
{
	if(index<1)
		return 0;

	if(dp2[index]!=-10000007)
		return dp2[index];

	int ans;
	ans=max(recur2(index-1), recur2(index-2));
	return dp2[index]=ans+a[index];
}

int main()
	{
		int i, k;
		int ans=INT_MIN;

		cin >> n >> k;

		for(i=1; i<=n; i++)
			cin >> a[i];

		for(i=0; i<3007; i++)
			{
				dp1[i]=-10000007;
				dp2[i]=-10000007;
			}

		recur1(k);
		recur2(n);

		/*
		for(i=1; i<=n; i++)
			cout << dp1[i] << " ";
		cout << endl;

		for(i=1; i<=n; i++)
			cout << dp2[i] << " ";
		cout << endl;
		*/
		for(i=k+1; i<=n; i++)
			ans=max(ans, dp1[i]+dp2[i]);

		cout << ans << endl;

		return 0;
	}