#include <bits/stdc++.h>
#include <unordered_map>

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

vvi g(N);
int c[N], dp[N], dp2[N];
map < pair <int, int>, int> mx;
vector < pair <int, int> > levels[N];

void dfs(int idx, int p = -1, int lvl = 1)
{
	levels[lvl].pb(mp(idx, p));
	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) dfs(g[idx][i], idx, lvl + 1);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> c[i];

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		dfs(1);

		// for(i = 1; i <= 3; i++) {
		// 	cout << i << endl;
		// 	for(j = 0; j < levels[i].size(); j++) 
		// 		cout << levels[i][j].f << " " << levels[i][j].s << endl;
		// }

		for(i = 1; i <= m; i++)
			{
				cin >> u >> v;
				mx[mp(u, v)] = i;
			}

		
		return 0;
	}