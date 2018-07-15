#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector <int> g[100007];
bool vis[100007][4];
int sz[100007], color[100007];
bool ans = 0, cyl = 0;
int white = 0, grey = 1, black = 2;
vector <int> ansv, vx;

bool cycle(int x)
{
	color[x] = grey;
	for(int y : g[x]){
		if(color[y] == grey) return 1;
		if(color[y] == white && cycle(y)) return 1;
	}
	color[x] = black;
	return 0;
}


int dfs(int idx, int lvl)
{
	if(ans) return 0;

	if(vis[idx][lvl]) return 0;

	vis[idx][lvl] = 1;

	if(lvl == 1 && sz[idx] == 0)
		{
			ans = 1;
			ansv.pb(idx);
			return 1;
		}

	for(int i = 0; i < g[idx].size(); i++)
		{
			if(ans) break;
			if(dfs(g[idx][i], (lvl + 1) % 2))
				{
					ansv.pb(idx);
					return 1;
				}
		}

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, u, v, i, j, s;

		cin >> n >> m;

		for(i = 1; i <= n; i++)
			{
				cin >> sz[i];

				for(j = 0; j < sz[i]; j++)
					{
						cin >> v;
						g[i].pb(v);
					}
			}

		cin >> s;
		vx.pb(s);
		dfs(s, 0);

		if(ans)
			{
				cout << "Win" << endl;
				for(i = ansv.size() - 1; i >= 0; i--) cout << ansv[i] << " "; cout << endl;
			}
		else if(cycle(s)) cout << "Draw\n";
		else cout << "Lose\n";

		return 0;
	}