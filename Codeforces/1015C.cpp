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
	return a.s > b.s;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, sum = 0, ans = 0;

		cin >> n >> m;

		for(i = 0; i < n; i++) 
			{
				cin >> u >> v;
				vs.pb(mp(mp(u, v), u - v));
				sum += u;
			}

		sort(vs.begin(), vs.end(), cmp);

		for(i = 0; i < n; i++)
			{
				if(sum > m) 
					{
						sum = sum - vs[i].f.f + vs[i].f.s;
						ans++;
					}
				else break;
			}

		if(sum > m) ans = -1;

		cout << ans << endl;

		return 0;
	}