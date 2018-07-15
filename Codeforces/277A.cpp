#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > vs(107);
vector < vector <int> > g(107);
bool vis[107];

void dfs(int idx)
{
	if(vis[idx]) return;
	vis[idx] = 1;
	for(int i = 0; i < g[idx].size(); i++) dfs(g[idx][i]);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, k, u, v, ans = 0;
		bool lang = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			{
				cin >> u;
				if(u) lang = 1;
				for(j = 0; j < u; j++) cin >> v, vs[v].pb(i);
			}

		for(i = 0; i < vs.size(); i++)
			for(j = 0; j < vs[i].size(); j++)
				for(k = 0; k < vs[i].size(); k++)
					if(j != k)
						g[vs[i][j]].pb(vs[i][k]);
		
		for(i = 1; i <= n; i++)
			if(!vis[i])
				{
					ans++;
					dfs(i);
				}

		if(lang) ans--;
		cout << ans << endl;
		return 0;
	}