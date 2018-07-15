#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int ax[1007], extortion[1007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, a, b, c, t, u, v, i, j, ans = 0;

		cin >> n >> a >> b >> c >> t;

		for(i = 0; i < n; i++) cin >> ax[i];
		
		sort(ax, ax + n);

		for(i = 0; i < n; i++)
			{
				u = a;

				for(j = ax[i]; j <= t; j++)
					{
						extortion[i] = max(extortion[i], u + c * (j - ax[i]));
						u -= b;
					}

			}

		for(i = 0; i < n; i++) ans += extortion[i];
		cout << ans << endl;

		return 0;
	}