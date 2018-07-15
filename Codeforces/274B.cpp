#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(100007);
int a[100007];
int ans = 0;

int dfs(int idx, int p, int add)
{
	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p)
			add += dfs(g[idx][i], idx, add);

	int val = a[idx] + add;

	ans += abs(val);

	return -val;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i = 1; i <= n; i++) cin >> a[i];

		v = 0;
		dfs(1, 0, v);

		cout << ans << endl;

		return 0;
	}