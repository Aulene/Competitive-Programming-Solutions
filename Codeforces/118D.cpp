#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 100000000
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int N = 107;

int n1, n2, k1, k2;
int dp[N][N][7];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int i, j, k, u, v, ans = 0;
		
		cin >> n1 >> n2 >> k1 >> k2;

		dp[0][0][0] = dp[0][0][1] = 1;

		for(i = 0; i <= n1; i++) {
			for(j = 0; j <= n2; j++) {
				for(k = 1; k <= min(k1, i); k++)
					dp[i][j][0] = (dp[i][j][0] + dp[i - k][j][1]) % mod;
				for(k = 1; k <= min(k2, j); k++)
					dp[i][j][1] = (dp[i][j][1] + dp[i][j - k][0]) % mod;
			}
		}

		ans = (dp[n1][n2][0] + dp[n1][n2][1]) % mod;

		cout << ans << endl;

		return 0;
	}