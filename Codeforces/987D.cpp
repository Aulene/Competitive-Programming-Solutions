#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int a[100007];
vector < vector <int> > vs(100007);

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v, k, s;

		cin >> n >> m >> k >> s;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				vs[u].pb(v);
				vs[v].pb(u);
			}
		return 0;
	}