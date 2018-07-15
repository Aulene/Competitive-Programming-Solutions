#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair <int, int> > vs;

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, ans = -1;

		cin >> n;

		for(i = 0; i < n; i++) {
				cin >> u >> v;
				vs.pb(mp(u, v));
			}

		sort(vs.begin(), vs.end());

		// for(i = 0; i < n; i++) cout << vs[i].f << " " << vs[i].s << endl;

		for(int i = 0; i < n; i++)
			{
				if(ans <= vs[i].s) {
					ans = vs[i].s;
				}
				else {
					ans = vs[i].f;
				}
			}

		cout << ans << endl;

		return 0;
	}