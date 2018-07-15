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

bool cmp(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b)
{
	// if(a.f.s == b.f.s) 
	if(a.f.f != b.f.f) return a.f.f < b.f.f;
	return a.f.s < b.f.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;
		pair <int, int> ans = mp(-1, -1);

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(mp(u, v), i + 1));
			}

		sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < n; i++)
		// 	cout << vs[i].f.f << " " << vs[i].f.s << endl;

		for(i = 0; i < n - 1; i++)
			{
				int x1 = vs[i].f.f, x2 = vs[i + 1].f.f;
				int y1 = vs[i].f.s, y2 = vs[i + 1].f.s;
				
				if(x2 >= x1 && y2 <= y1) {
					ans = mp(vs[i + 1].s, vs[i].s);
					break;
				}
				else if(x1 == x2 && y1 <= y2) {
					ans = mp(vs[i].s, vs[i + 1].s);
					break;
				}
			}

		cout << ans.f << " " << ans.s << endl;

		return 0;
	}