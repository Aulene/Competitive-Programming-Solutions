#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

// int dp2[200007][27]; //dp2[i][j] = maxdmg that can be done until ith creature by using spell A j times


int health[200007], d[200007];
int dp[200007][27]; // dp[i][j] = maxdmg that can be done by ith creature by using spell A j times on it
int dp2[200007][27][3]; //dp2[i][j] = maxdmg that can be done until ith creature by using spell A j times
						// [0] - does not use spell b on i, [1] uses spell b on i
int h[200007][27]; // h[i][j] = h after doubling j times

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, a, b, i, j, k, l, u, v, ans = 0;

		cin >> n >> a >> b;	
		
		for(i = 1; i <= n; i++)
			cin >> health[i] >> d[i];

		for(i = 1; i <= n; i++)
			{
				h[i][0] = health[i];

				for(j = 1; j <= a; j++)
					h[i][j] = 2 * h[i][j - 1];
			}

		for(i = 1; i <= n; i++)
			{
				dp[i][0] = max(d[i], health[i]);

				for(j = 1; j <= a; j++) 
					dp[i][j] = max(dp[i][j - 1], h[i][j]);
			}

		// cout << "HEALTH" << endl;
		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 0; j <= a; j++) cout << h[i][j] << " "; cout << endl;
		// 	}
		// cout << "HEALTH OVER" << endl;

		// cout << "MAX DMG BY I AT J" << endl;
		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 0; j <= a; j++) cout << dp[i][j] << " "; cout << endl;
		// 	}
		// cout << "MAX DMG BY I AT J OVER" << endl;
		
		// dp2[1][0] = dp[1][0];

		// for(i = 1; i <= n; i++)
		// 	{
		// 		int ans = 0;

		// 		for(j = 1; j <= a; j++)
		// 			for(k = 0; k <= j; k++)
		// 				dp2[i][j] = max(dp2[i][j - 1], dp[i][k] + dp2[i - 1][j - k]);
		// 	}

		for(i = 1; i <= n; i++)
			{
				for(j = 0; j <= a; j++)
					dp2[i][j][0] = d[i] + max(dp2[i - 1][j][0], dp2[i - 1][j][1]);
				
				for(j = 0; j <= a; j++)
					{
						for(k = 0; k <= j; k++)
							{
								for(l = 0; l < 2; l++)
									dp2[i][j][1] = max(dp2[i][j][1], dp2[i - 1][j - k][l] + dp[i][k]);
							}
					}
			}

		for(i = 0; i <= a; i++)
			{
				ans = max(ans, dp2[n][i][0]);
				ans = max(ans, dp2[n][i][1]);
			}
		// cout << "ANS DP2" << endl;
		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 0; j <= a; j++) cout << dp2[i][j] << " "; cout << endl;
		// 	}
		
		// cout << "ANS DP2 OVER" << endl;
		

		cout << ans << endl;
		return 0;
	}