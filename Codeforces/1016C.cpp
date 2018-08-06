#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[300007][3];
int dpr[3], dpl[3], dps[3];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, t;
		int ans, pre = 0, maxans = 0;

		cin >> n;

		for(i = 0; i < 2; i++)
			for(j = 0; j < n; j++) cin >> a[i][j];

		for(i = 0; i < 2; i++)
			{
				dpl[i] = 0;
				for(j = 1; j < n; j++)
					dpl[i] = dpl[i] + a[i][j] * j;
			}

		for(i = 0; i < 2; i++)
			{
				dpr[i] = 0;
				for(j = 1; j < n; j++)
					dpr[i] = dpr[i] + a[i][n - 1 - j] * j;
			}

		dps[0] = dps[1] = 0;
		for(i = 0; i < 2; i++)
			for(j = 0; j < n; j++) dps[i] += a[i][j];

		for(i = 0; i < n; i++)
			{
				if(i & 1)
					{
						ans = dpl[0] + dpr[1] + pre;
						ans += (n - i) * dps[0];
						pre += (2 * i * a[1][i]) + (((2 * i) + 1) * a[0][i]);
						maxans = max(ans, maxans);
					}
				else
					{
						ans = dpl[0] + dpr[1] + pre;
						ans += (n - i) * dps[1];
						pre += (2 * i * a[0][i]) + (((2 * i) + 1) * a[1][i]);
						maxans = max(ans, maxans);
					}

				dps[0] -= a[0][i];
				dps[1] -= a[1][i];
				dpl[0] -= dps[0];
				dpl[1] -= dps[1];
				dpr[0] -= (n - i) * a[0][i];
				dpr[1] -= (n - i) * a[1][i];
			}

		cout << maxans << endl;

		return 0;
	}