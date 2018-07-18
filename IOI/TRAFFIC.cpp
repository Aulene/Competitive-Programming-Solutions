#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(1000007);
int a[1000007], sum[1000007];
int ansC = INT_MAX, ans;

void dfsSum(int idx, int p = -1)
{
	sum[idx] = a[idx];

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) {
			dfsSum(g[idx][i], idx);
			sum[idx] += sum[g[idx][i]];
		} 
			
}

void dfs(int idx, int x = 0, int p = -1)
{
	int mx = x;

	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p)
			{
				int v = g[idx][i];

				dfs(v, x + sum[idx] - sum[v], idx);
				mx = max(mx, sum[v]);
			}

	if(mx < ansC) {
		ansC = mx;
		ans = idx;
	}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, i, j, u ,v;

		cin >> n;

		for(i = 0; i < n; i++) cin >> a[i];

		for(i = 1; i <= n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		dfsSum(0);
		dfs(0);

		cout << ans << endl;

		return 0;
	}