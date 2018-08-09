#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair < pair <int, int>, int> > vs;

bool cmp(pair < pair <int, int>, int > a, pair < pair <int, int>, int > b)
{
	return a.s < b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, w, ans = 1, idx = 0;

		cin >> n;

		for(i = 0; i < n; i++) {
			cin >> u >> v;
			vs.pb(mp(mp(u, v), u + v));
		}

		sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < n; i++) cout << vs[i].f.f << " " << vs[i].f.s << " " << vs[i].s << endl;

		for(i = 1; i < n; i++) {
			if(vs[idx].f.f + vs[idx].f.s <= vs[i].f.f - vs[i].f.s) {
				idx = i;
				ans++;
			}
		}

		cout << ans << endl;

		return 0;
	}