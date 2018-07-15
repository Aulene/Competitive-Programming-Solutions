#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 998244353
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[1007], a[1007];
int c[1007][1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0, ansx;

		for(i = 0; i < 1007; i++)
			{
				c[i][0] = c[i][i] = 1;

				for(j = 1; j < i; j++)
					c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			}

		cin >> n;
for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	dp[n] = 1;
	for(int i = n - 1; i >= 0; --i){
		if(a[i] <= 0) continue;
		
		for(int j = i + a[i] + 1; j <= n; ++j){
				dp[i] += (dp[j] * 1LL * c[j - i - 1][a[i]]) % mod;
				dp[i] %= mod;
		}
	}

		for(i = 0; i < n; i++) ans += dp[i], ans = ans % mod;

		cout << ans << endl;
		return 0;
	}