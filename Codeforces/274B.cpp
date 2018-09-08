#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define N 100007

int a[N];
int ans = 0;

vvi g(N);

pair <int, int> dfs(int idx, int p = -1)
{
	int cur;
	pair <int, int> fx, ret = {0, 0};

	for(int i = 0; i < g[idx].size(); i++)
		{
			int u = g[idx][i];

			if(u != p) {
				fx = dfs(u, idx);
				ret.f = max(fx.f, ret.f);
				ret.s = max(fx.s, ret.s);
			}
		}
	
	cur = a[idx] + ret.f - ret.s;

	if(cur < 0) ret.f += -cur;
	else ret.s += cur;

	return ret;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i = 1; i <= n; i++) cin >> a[i];

		pair <int, int> ans = dfs(1);
		cout << ans.f + ans.s << endl;

		return 0;
	}