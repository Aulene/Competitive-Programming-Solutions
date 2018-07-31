#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[5007], p[5007];
vector < pair < pair <int, int>, int> > vs;
vector < pair <int, int> > vx;

bool check(pair <int, int> a)
{
	for(int i = 0; i < vx.size(); i++)
		if((a.f <= vx[i].f && vx[i].f <= a.s) || (a.f <= vx[i].s && vx[i].s <= a.s)) return 0;
	return 1;
}

bool cmp(pair < pair <int, int>, int> a, pair < pair <int, int>, int> b)
{
	if(a.s != b.s) return a.s > b.s;
	return a.f.s > b.f.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, k, i, j, u, v, ans = 0;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];

		for(i = n; i >= 1; i--)
			{
				int u = i - m + 1;
				if(u >= 1)
					vs.pb(mp(mp(u, i), p[i] - p[u - 1]));
			}

		sort(vs.begin(), vs.end(), cmp);

		// for(i = 0; i < vs.size(); i++) cout << vs[i].f.f << " " << vs[i].f.s << " " << vs[i].s << endl;

		for(i = 0; i < vs.size(); i++)
			if(k)
				{
					if(check(vs[i].f)) {
						ans += vs[i].s;
						vx.pb(vs[i].f);
						k--;
					}
				}

		cout << ans << endl;

		return 0;
	}