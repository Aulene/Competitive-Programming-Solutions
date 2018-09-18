#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 

int a[200007], diff[200007];
vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, l, r, ans;
		int h;
		cin >> n >> m;
		
		ans = h = m;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(u, v));
			}

		for(i = 1; i <= n; i++)
			a[i] = vs[i - 1].s - vs[i - 1].f;

		for(i = 1; i <= n - 1; i++)
			diff[i] = vs[i].f - vs[i - 1].s;
		
		// cout << endl;
		// for(i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << diff[i] << " "; cout << endl;
		// cout << endl;

		l = r = 1, u = 0;

		while(r <= n)
			{
				u += a[r];
				ans = max(ans, u + h);
				m -= diff[r];

				while(m <= 0 && l <= r) 
					{
						u -= a[l];
						m += diff[l];
						l++;
					}

				// cout << l << " " << r << " " << u << " " << m << endl;
				r++;
			}

		cout << ans << endl;

		return 0;
	}