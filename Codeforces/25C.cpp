#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[307][307];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, w, sum = 0;

		cin >> n;

		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++) cin >> dp[i][j], sum += dp[i][j];

		cin >> m;

		while(m--)
			{
				cin >> u >> v >> w;

				if(w < dp[u][v]) {
					sum = sum - 2 * dp[u][v] + 2 * w;
					dp[u][v] = dp[v][u] = w;
				}
				

				for(i = 1; i <= n; i++)
					for(j = 1; j <= n; j++)
						if(dp[i][j] > dp[i][u] + dp[u][v] + dp[v][j]) {
							sum = sum - 2 * dp[i][j] + 2 * (dp[i][u] + dp[u][v] + dp[v][j]);
							dp[i][j] = dp[j][i] = dp[i][u] + dp[u][v] + dp[v][j];
						}

				// for(i = 1; i <= n; i++) {
				// 	for(j = 1; j <= n; j++) cout << dp[i][j] << " "; cout << endl;
				// }

				cout << sum / 2 << " ";
			}	cout << endl;
		return 0;
	}