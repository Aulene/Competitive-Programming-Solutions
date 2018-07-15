#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> vs;
int a[100007];
int sx[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = 0;
		int x, y;
		vector <int> :: iterator it;

		cin >> n;

		// for(i = 0; i < n; i++) a[i] = i + 1, vs.pb(i + 1);
		for(i = 0; i < n; i++) cin >> a[i], vs.pb(a[i]);

		sort(vs.begin(), vs.end());

		// for(i = 0; i < n; i++) cout << vs[i] << " "; cout << endl;

		u = 0, v = 0;

		// for(i = 0; i < n; i++)
		// 	{
		// 		it = upper_bound(vs.begin() + u, vs.end(), vs[i]);

		// 		if(it != vs.end()) {
		// 			u = it - vs.begin();
		// 			v = vs[i];
		// 			vs[i] = vs[u];
		// 			vs[u] = v;
		// 			ans++;
		// 		}
		// 	}

		while(u < n && v < n)
			{
				// if(sx[u]) {
				// 	u++;
				// 	continue;
				// }

				if(vs[v] == vs[u]) {
					v++;
					continue;
				}

				if(vs[v] > vs[u]) {
					sx[u] = sx[v] = 1;
					v++, u++, ans++;
					continue;
				}
			}

		// for(i = 0; i < n; i++) cout << vs[i] << " "; cout << endl;

		cout << ans << endl;
		return 0;
	}