#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int dp[5007];
int a[5007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, ans = -1;

		cin >> n;
		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n; i++) dp[i] = 1;

		for(i = 1; i <= n; i++)
			{
				for(j = 1; j < i; j++)
					if((abs(a[i]) > abs(a[j])))
						{
							if((a[j] > 0 && a[i] < 0) || (a[j] < 0 && a[i] > 0))
								dp[i] = max(dp[i], dp[j] + 1);
						}
			}

		for(i = 1; i <= n; i++) ans = max(ans, dp[i]);

		cout << ans << endl;
	
		return 0;
	}