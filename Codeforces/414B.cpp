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

lli n, k;
lli dp[2007][2007];

int main()
	{
		lli i, j, k, K;
		lli ans=0;

		cin >> n >> K;

		for(i=1; i<=n; i++)
			dp[1][i]=1;

		for(i=2; i<=K; i++)
			for(j=1; j<=n; j++)
				for(k=j; k<=n; k+=j)
					dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
					
		for(i=1; i<=n; i++)
			ans=(ans+dp[K][i])%mod;

		cout << ans << endl;
		return 0;
	}