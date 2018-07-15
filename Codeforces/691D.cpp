#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

int ax[1000007];
bool vis[1000007];
int ans[1000007];

vector < vector <int> > vs(1000007);
vector <int> a(1000007), b(1000007);

void dfs(int idx)
{
	if(vis[idx]) return;

	// cout << idx << " " << ax[idx] << endl;

	vis[idx] = 1;

	a.pb(idx);
	b.pb(ax[idx]);

	for(int i = 0; i < vs[idx].size(); i++) 
		dfs(vs[idx][i]);

	return;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> ax[i];

		for(i = 0; i < m; i++)
			{
				cin >> u >> v;
				vs[u].pb(v);
				vs[v].pb(u);
			}

		// for(i = 1; i <= n; i++)
		// 	{
		// 		for(j = 0; j < vs[i].size(); j++) 
		// 			// cout << vs[i][j] << " "; cout << endl;
		// 	}

		for(i = 1; i <= n; i++)
			if(!vis[i])
				{
					a.clear();
					b.clear();

					dfs(i);

					sort(a.begin(), a.end());
					sort(b.begin(), b.end(), greater <int> ());

					// for(j = 0; j < a.size(); j++) cout << a[j] << " "; cout << endl;
					// for(j = 0; j < a.size(); j++) cout << b[j] << " "; cout << endl;
					
					for(j = 0; j < a.size(); j++) ans[a[j]] = b[j];
				}

		for(i = 1; i <= n; i++) cout << ans[i] << " "; 
		return 0;
	}