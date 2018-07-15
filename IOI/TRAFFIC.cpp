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
int a[1000007];
int ansC = INT_MAX, ans;
int sum = 0;

int dfs1(int idx, int p)
{
	int anus = 0;

	if(p == -1)
		{
			for(int i = 0; i < g[idx].size(); i++)
				if(g[idx][i] != p)
					anus = max(dfs1(g[idx][i], idx), anus);
			
			if(anus < ansC)
				{
					ansC = anus;
					ans = idx;
				}
		}
	else
		{
			anus = a[idx];

			for(int i = 0; i < g[idx].size(); i++)
				if(g[idx][i] != p)
					anus += dfs1(g[idx][i], idx);

			return anus;
		}
	
	return 0;
}

int dfs2(int idx, int p, int upsum, int downsum)
{
	int anus = max(upsum, downsum);

	if(anus < ansC)
		{
			ansC = anus;
			ans = idx;
		}
	
	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) dfs2(g[idx][i], idx, upsum + a[idx], downsum - a[idx]);

	return 0;
}

void dfsSum(int idx, int p)
{
	sum += a[idx];
	for(int i = 0; i < g[idx].size(); i++)
		if(g[idx][i] != p) dfsSum(g[idx][i], idx);
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

		// dfsSum(0, -1);
		// cout << sum << endl;
		
		if(n <= 1000)
			{
				for(i = 0; i < n; i++)
					dfs1(i, -1);
			}
		else
			{
				dfsSum(0, -1);
				dfs2(0, -1, 0, sum);
			}

		cout << ans << endl;

		return 0;
	}