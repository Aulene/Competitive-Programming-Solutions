#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007], dp[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, ans = 0;
		bool chg;

		cin >> n;

		dp[0] = 1;
		for(i = 1; i <= n; i++) {
			// dp[i] = i + 1;
			cin >> a[i];
		}
			

		for(i = 0; i < n; i++)
			if(a[i] < a[i + 1]) dp[i] = i + 1;
			else dp[i] = n + 1;

		chg = 1;

		cout << "dp" << endl;
		for(i = 0; i <= n; i++) cout << i << " "; cout << endl;
		for(i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;
		cout << "/dp" << endl;

		while(chg)
			{
				chg = 0;

				for(i = n - 1; i >= 0; i--) {
					if(a[i] > a[dp[i]]) {
						cout << i << " " << dp[i] << endl;
						dp[i] = dp[dp[i]];
						chg = 1;
					}
				}

				for(i = 0; i <= n; i++) cout << dp[i] << " "; cout << endl;

				if(!chg) break;
				else ans++;
			}

		cout << ans << endl;
		return 0;
	}