#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

vector < vector <int> > g(3007);
vector <int> cyc;
bool vis[3007];
int parent[3007];

void cycle(int u, int p)
{
	vis[u] = 1;

	for(int i = 0; i < g[u].size(); i++) {
		if(!vis[g[u][i]]) {
			parent[g[u][i]] = u;
		}
		else if(parent[g[u][i]] != u) {
			cyc.pb(u);
			cout << u << endl;
		}
	}
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n; i++)
			{
				cin >> u >> v;
				g[u].pb(v);
				g[v].pb(u);
			}

		for(i = 1; i <= n; i++) parent[i] = i;

		cycle(1);

		return 0;
	}