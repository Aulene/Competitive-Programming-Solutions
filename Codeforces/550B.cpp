#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int a[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		// cout.tie(NULL);

		int n, m, l, r, x, i, j, u, v, ans = 0;
		int maxx, minx, tot;

		cin >> n >> l >> r >> x;

		for(i = 1; i <= n; i++) cin >> a[i];

		m = pow(2, n);

		for(i = 0; i <= m; i++)
			{

				tot = maxx = 0;
				minx = INT_MAX;

				v = i;

				bitset <8> c(v);
				// cout << c << " " << i << endl;

				while(v) {
					u = log2(v & -v) + 1;

					// cout << u << " " << a[u] << endl;
					
					tot += a[u];
					minx = min(minx, a[u]);
					maxx = max(maxx, a[u]);

					v = v & (v - 1);
				}

				// cout << endl;
				// cout << "MIN = " << minx << endl;
				// cout << "MAX = " << maxx << endl;
				// cout << "TOT = " << tot << endl;

				if(tot >= l && tot <= r && (maxx - minx >= x)) ans++;
			}

		cout << ans << endl;

		return 0;
	}