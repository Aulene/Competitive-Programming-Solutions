#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int x[100007], d[100007];
int s[100007];
long double ans;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, sum = 0;
		int maxx = -1e18, minx = 1e18;

		cin >> n >> m;

		for(i = 1; i <= m; i++) cin >> x[i] >> d[i];

		for(i = 1; i <= n; i++)
			{
				u = ((i - 1) * i) / 2;
				v = ((n - i) * (n - i + 1)) / 2;
				s[i] = u + v;
			}

		// for(i = 1; i <= n; i++) cout << s[i] << " "; cout << endl;

		for(i = 1; i <= n; i++) {
			maxx = max(maxx, s[i]);
			minx = min(minx, s[i]);
		}

		// cout << maxx << " " << minx << endl;

		for(i = 1; i <= m; i++)
			{
				// cout << i << " " << x[i] << " " << d[i] << endl;

				u = sum + (n * x[i]) + (maxx * d[i]);
				v = sum + (n * x[i]) + (minx * d[i]);
				
				// cout << i << " " << u << " " << v << endl;

				sum = max(u, v);
			}

		// cout << sum << endl;

		ans = (long double) sum / n;

		// cout << ans << setprecision(9) << endl;
		printf("%0.15Lf\n", ans);

		return 0;
	}