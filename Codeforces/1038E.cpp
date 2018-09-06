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

vvi color(100007);
bool vis[100007];
int a[100007];
vvi cnode(100007);
int ans = 0;

int dfs(int idx, int c = 0, int sum = 0, int level = 0)
{
	if(vis[idx]) return 0;

	// for(int i = 0; i < level; i++) cout << " "; cout << "IDX = " << idx << " COLOR = " << c << " SUM = " << sum << endl;

	sum += a[idx];
	ans = max(ans, sum);
	vis[idx] = 1;

	int u, v, i, j;

	if(c == 0)
		{
			for(i = 0; i < color[cnode[idx][0]].size(); i++) {
				u = color[cnode[idx][0]][i];
				dfs(u, cnode[idx][0], sum, level + 1);
			}

			for(i = 0; i < color[cnode[idx][1]].size(); i++) {
				u = color[cnode[idx][1]][i];
				dfs(u, cnode[idx][1], sum, level + 1);
			}

			vis[idx] = 0;

			return 0;
		}

	if(cnode[idx][0] == c && cnode[idx][1] == c)
		{
			for(i = 0; i < color[c].size(); i++) {
				u = color[c][i];
				dfs(u, c, sum, level + 1);
			}

			vis[idx] = 0;
			return 0;
		}

	// for(i = 0; i < cnode[idx].size(); i++) cout << cnode[idx][i] << " "; cout << endl;

	if(cnode[idx][0] == c) v = cnode[idx][1];
	else v = cnode[idx][0];

	// cout << v << endl;

	for(i = 0; i < color[v].size(); i++) {
		u = color[v][i];
		dfs(u, v, sum, level + 1);
	}

	vis[idx] = 0;

	return 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		int n, m, i, j, u, v, c1, c2;

		cin >> n;

		for(i = 1; i <= n; i++)
			{
				cin >> c1 >> a[i] >> c2;
				color[c1].pb(i);
				color[c2].pb(i);
				cnode[i].pb(c1);
				cnode[i].pb(c2);
			}

		for(i = 1; i <= n; i++) dfs(i);
		cout << ans << endl;

		return 0;
	}