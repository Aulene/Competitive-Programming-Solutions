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
vector < queue <int> > pos(1007);
vector < pair <int, int> > ansv;
multiset <int> zucc;
int a[1007];

bool cmp(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b)
{
	if(a.f.s == b.f.s)
		return a.f.f < b.f.f;
	return a.f.s > b.f.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, c, p, i, j, u, v;
		int ans = 0, ansx = 0;
		set <int> :: iterator it;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> u >> v;
				vs.pb(mp(mp(u, v), i));	
			}

		sort(vs.begin(), vs.end(), cmp);

		cin >> m;

		for(i = 1; i <= m; i++)
			{
				cin >> a[i];
				pos[a[i]].p(i);
				zucc.insert(a[i]);			
			}

		// for(it = zucc.begin(); it != zucc.end(); ++it) 
		// 	cout << *it << endl;

		for(i = 0; i < n; i++)
			{
				it = zucc.lower_bound(vs[i].f.f);
				v = *it;

				// if(it != zucc.end())
				// 	cout << vs[i].f.f << " " << v << endl;

				if(it != zucc.end())
					{
						ans++;
						ansx += vs[i].f.s;

						u = pos[v].front();
						pos[v].pop();

						ansv.pb(mp(vs[i].s, u));
						zucc.erase(it);
					}
			}

		cout << ans << " " << ansx << endl;
		for(i = 0; i < ansv.size(); i++)
			cout << ansv[i].f << " " << ansv[i].s << endl;


		return 0;
	}