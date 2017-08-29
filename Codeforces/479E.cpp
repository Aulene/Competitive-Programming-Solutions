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

lli dp[5007][5007];
lli pref[5007];

// dp[i][j] = no of floors visited from i in j trips

int main()
	{
		lli n, a, b, K, i, j, k;
		lli dist, sum, ans=0;
		lli l, r;

		cin >> n >> a >> b >> K;

		dp[a][0]=1;

		for(i=1; i<=K; i++)
			{
				for(j=1; j<=n; j++)
					pref[j]=(pref[j-1]+dp[j][i-1]);

				for(j=1; j<=n; j++)
					{
						if(j==b)
							continue;

						if(j<b)
							{
								l=1;
								r=(j+b-1)/2;
							}
						else
							{
								l=(j+b)/2+1;
								r=n;
							}

						dp[j][i]=(dp[j][i]+pref[r]-pref[l-1]+mod)%mod;
						dp[j][i]=(dp[j][i]-dp[j][i-1]+mod)%mod;
					}
			}
		//sum(l,r)=sum(1,r)-sum(1,l-1)

		/*
		for(i=1; i<=K; i++)
			{
				for(j=1; j<=n; j++)
					cout << dp[j][i] << " ";
				cout << endl;
			}
		*/	
			
		for(i=1; i<=n; i++)
			ans=(ans+dp[i][K])%mod;

		cout << ans << endl;
		return 0;
	}