#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < pair < pair <int, int>, int > > vs;
int a[100007];
int pre[100007], ans[100007];

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, k, i, j, u, v, x;
		pair < pair <int, int>, int> pz;

		cin >> n >> m >> k;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < m; i++)
			{
				cin >> u >> v >> x;
				vs.pb(mp(mp(u, v), x));
			}

		for(i = 0; i < k; i++)
			{
				cin >> u >> v;
				pre[u]++;
				pre[v + 1]--;
			}

		for(i = 1; i <= m; i++) pre[i] += pre[i - 1];

		for(i = 1; i <= m; i++)
			{
				pz = vs[i - 1];
				u = pz.f.f, v = pz.f.s, x = pz.s;

				x = x * pre[i];

				ans[u] += x;
				ans[v + 1] += -x;
			}

		for(i = 1; i <= n; i++)
			ans[i] = ans[i - 1] + ans[i];

		for(i = 1; i <= n; i++)
			cout << ans[i] + a[i] << " ";
		return 0;
	}