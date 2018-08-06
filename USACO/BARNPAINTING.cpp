#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(100007);
int a[100007];
int dp[100007][4];

lli recur(int idx, int c, int pv, int pc)
{
	if(c == pc || (a[idx] && c != a[idx])) return 0;

	if(dp[idx][c] != -1) return dp[idx][c];

	dp[idx][c] = 1;

	for(int i = 0; i < g[idx].size(); i++)
		{
			int u = g[idx][i];

			if(u == pv) continue;

			lli ans = 0;

			for(int j = 1; j <= 3; j++) 
				ans = (ans + recur(u, j, idx, c)) % mod;

			dp[idx][c] = (dp[idx][c] * ans) % mod;
		}

	return dp[idx][c];
}

int main()
	{	
		int n, m, i, j, u, v;
		lli ans = 0;
		
		for(i = 0; i < 100007; i++) a[u] = 0;
		for(i = 0; i < 100007; i++) 
			for(j = 0; j < 7; j++) dp[i][j] = -1;
		
		cin >> n >> m;

		for(i = 0; i < n - 1; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		
		for(i = 1; i <= m; i++) cin >> u >> v, a[u] = v;

		for(i = 1; i <= 3; i++) ans = (ans + recur(1, i, -1, -1)) % mod;

		cout << ans << endl;

		return 0;
	}