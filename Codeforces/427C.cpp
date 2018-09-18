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
#define N 100007

int vis[N], a[N], onStack[N], low[N], ids[N];
vvi g(N), g2(N);
vvi sccs;
vi path;
stack <int> sx;
int id = 1;

void findSCC(int idx)
{
	/*
	// put next lines in main
	// memset(ids, -1, sizeof(ids));
	// for(i = 1; i <= n; i++)
	// 	if(ids[i] == -1) findSCC(i);
	*/

	sx.push(idx);
	onStack[idx] = 1;
	ids[idx] = low[idx] = id++;

	for(int i = 0; i < g[idx].size(); i++) 
		{
			int u = g[idx][i];

			if(ids[u] == -1)
				{
					findSCC(u);
					low[idx] = min(low[idx], low[u]);
				}
			else if(onStack[u]) 
				low[idx] = min(low[idx], ids[u]);
		}

	if(ids[idx] == low[idx]) 
		{
			vector <int> path;

			while(sx.top() != idx) 
				{
					int u = sx.top();
					sx.pop();
					onStack[u] = 0;
					path.pb(u);
				}

			int u = sx.top();
			sx.pop();
			onStack[u] = 0;
			path.pb(u);

			sccs.emplace_back();
			sccs.back() = path;
		}
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

		memset(ids, -1, sizeof(ids));
		int n, m, i, j, u, v, idx;
		int ans1 = 0, ans2 = 1;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		cin >> m;

		while(m--)
			{
				cin >> u >> v;
				g[u].pb(v);
			}

		for(i = 1; i <= n; i++)
			if(ids[i] == -1) findSCC(i);

		// for(i = 1; i <= n; i++) cout << low[i] << " "; cout << endl;

		// for(i = 0; i < sccs.size(); i++) {
		// 	for(j = 0; j < sccs[i].size(); j++) cout << sccs[i][j] << " "; cout << endl;
		// }

		for(i = 0; i < sccs.size(); i++)
			{
				u = INT_MAX, v = 0;

				for(j = 0; j < sccs[i].size(); j++) {
					if(a[sccs[i][j]] < u) {
						u = a[sccs[i][j]];
						v = 1;
					}
					else if(a[sccs[i][j]] == u) {
						v++;
					}
				}

				ans1 += u;
				ans2 = (ans2 * v) % mod;
			}

		cout << ans1 << " " << ans2 << endl;

		return 0;
	}