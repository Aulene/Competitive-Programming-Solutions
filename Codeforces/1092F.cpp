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
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define zp mp(0, 0)

const int N = 200007;

int a[N], up[N], down[N], ans[N];
vvi g(N);

int dfs(int idx = 1, int p = -1) {
	down[idx] = a[idx];
	for(auto it : g[idx])
		if(it != p) down[idx] += dfs(it, idx);

	return down[idx];
}

void dfsup(int idx = 1, int p = -1) {
	if(p != -1)
		up[idx] = up[p] + down[p] - down[idx];

	for(auto it : g[idx])
		if(it != p) dfsup(it, idx);
}

void dfs1(int idx = 1, int dist = 0, int p = -1) {
	ans[1] += dist * a[idx];
	for(auto it : g[idx])
		if(it != p) dfs1(it, dist + 1, idx);
}

void dfs2(int idx = 1, int p = -1) {
	if(p != -1)
		ans[idx] = ans[p] + up[idx] - down[idx];
	for(auto it : g[idx])
		if(it != p) dfs2(it, idx);
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, ansx = 0;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 1; i <= n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		dfs(); dfsup(); dfs1(); dfs2();

		// for(i = 1; i <= n; i++) cout << down[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << up[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;

		for(i = 1; i <= n; i++) ansx = max(ansx, ans[i]);

		cout << ansx << endl;

		return 0;
	}