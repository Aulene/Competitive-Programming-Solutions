#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <set>
#include <list>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int f[100007], a[100007], dp[100007];
unordered_map <int, int> M;
vector < vector <int> > g(100007);
vector < pair <int, int> > ones;

int cfib()
{
	f[1] = f[2] = 1;
	int l = pow(10, 18);

	M[1] = 2;
	for(int i = 3; f[i - 1] <= l; i++) f[i] = f[i - 1] + f[i - 2], M[f[i]] = i;

	return 0;
}

int dfs(int idx)
{
	if(dp[idx] != -1) return dp[idx];

	int ans = 0;

	for(int i = 0; i < g[idx].size(); i++)
		{
			int u = g[idx][i];
			ans = max(ans, dfs(u));
		}

	return dp[idx] = ans + 1;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cfib();

		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < 100007; i++) dp[i] = -1;

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;

				if(a[u] > a[v]) swap(u, v);
				
				if(a[u] == a[v] && a[u] == 1)
					{
						ones.pb(mp(u, v)); 
						continue;
					}

				if(M[a[u]] + 1 == M[a[v]] && M[a[u]] && M[a[v]]) 
					{
						g[u].pb(v); 
						// cout << u << " " << v << endl;
					}
			}

		for(i = 1; i <= n; i++)
			if(M[a[i]])
				{
					if(dp[i] == -1) ans = max(ans, dfs(i));
				}

		for(i = 0; i < ones.size(); i++)
			{
				pair <int, int> nz = ones[i];
				u = nz.f, v = nz.s;

				// cout << dp[u] << " " << dp[v] << endl;

				j = max(dp[u], dp[v]);
				ans = max(ans, j + 1);
			}

		cout << ans << endl;

		return 0;
	}