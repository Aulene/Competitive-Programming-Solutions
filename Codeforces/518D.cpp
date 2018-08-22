#include <bits/stdc++.h>

using namespace std;

#define double long double
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

double dp[2007][2007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, i, j, u, v, t;
		double p, ans = 0;
		
		cin >> n >> p >> t;

		for(i = 0; i < 2007; i++) dp[0][i] = 1;

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= t; j++)
					dp[i][j] = (double) dp[i][j - 1] * (1 - p) + dp[i - 1][j - 1] * p;
			}

		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= t; j++) printf("%.6Lf ", dp[i][j]); cout << endl;
		// }

		for(i = 1; i <= n; i++) ans += dp[i][t];

		printf("%.17Lf\n", ans);

		return 0;
	}