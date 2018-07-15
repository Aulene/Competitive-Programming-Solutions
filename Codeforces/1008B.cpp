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

		int n, i, j, u, v, prev = 0;
		bool ansx = 1;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(max(u, v), min(u, v)));
			}

		prev = vs[0].f;

		for(i = 1; i < n; i++)
			{
				if(vs[i].f <= prev) {
					prev = vs[i].f;
				}
				else if(vs[i].s <= prev) {
					prev = vs[i].s;
				}
				else ansx = 0;
			}

		if(ansx) cout << "YES\n";
		else cout << "NO\n";

		return 0;
	}