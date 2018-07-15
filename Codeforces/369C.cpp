#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int w[100007];
int vs[100007];
vector < vector <int> > g(100007);
vector <int> ansx;

int dfs(int idx, int p)
{
	if(w[idx]) vs[idx] = 1;

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p)
			{
				dfs(g[idx][i], idx);
				vs[idx] += vs[g[idx][i]];		
			}

	return vs[idx];
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u, v, wx, ans = 0;

		cin >> n;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v >> wx;
				if(wx == 2) {
					w[u] = 1;
					w[v] = 1;
				}

				g[u].pb(v);
				g[v].pb(u);
			}

		dfs(1, 0);
		for(i = 1; i <= n; i++)
			if(vs[i] == 1) ans++, ansx.pb(i);

		cout << ans << endl;
		for(i = 0; i < ansx.size(); i++) cout << ansx[i] << " ";
			
		return 0;
	}