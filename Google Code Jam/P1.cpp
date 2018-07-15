#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int n, m;
int a[1007], dp[1007][1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int t, i, j, k, u, v, sum, left, ans;

		cin >> t;

		while(t--)
			{
				sum = 0;
				ans = 0;

				cin >> n >> m;

				for(i = 1; i <= m; i++) cin >> a[i], sum += a[i];

				left = n - sum;

				for(i = 0; i < 1007; i++)
					for(j = 0; j < 1007; j++) dp[i][j] = 0;

				for(i = 1; i <= 1000; i++) 
					{
						for(j = 0; j <= left; j++) 
							{
								int add = (int) round((((double) (a[i] + j) / n)) * 100);

								dp[i][j] = add;

								for(k = 0; k < j; k++) 
									dp[i][j] = max(dp[i][j], add + dp[i - 1][k]);	
							}
					}

				for(i = 1; i <= n; i++)
					{
						for(j = 1; j <= left; j++)
							cout << dp[i][j] << " "; cout << endl;
 					}
				for(i = 1; i <= 1000; i++) ans = max(ans, dp[i][left]);

				cout << ans << endl;
			}

		return 0;
	}