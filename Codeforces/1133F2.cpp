#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
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

vpi ansv;
vvi g(N), g2(N);

int num_comps;
int con[N], vis[N], add[N];

void dfs(int idx, int p = 1) {
	if(vis[idx]) return; 
	vis[idx] = 1;
	
	if(p != 1) {
		g2[idx].pb(p), g2[p].pb(idx);

	for(auto it : g[idx])
		if(it != idx || it == 1 || vis[it]) dfs(it, idx);
}

void bfs() {
	memset(vis, 0, sizeof(vis));

	queue < pi > q;
	q.p({1, 0});

	while(!q.empty()) {
		pi pz = q.front(); q.pop();
		int i = pz.f, p = pz.s;
		vis[i] = 1;
		if(p) ansv.pb({i, p});
		for(auto it : g2[i])
			if(it != p && !vis[it]) q.p({it, i});
	}
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
		
		int n, m, r, i, j, u, v, deg = 0;

		cin >> n >> m >> r;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			if(v < u) swap(u, v);
			if(u == 1) con[v] = 1, deg++;
			g[u].pb(v); g[v].pb(u);
		}
		
		cout << endl;

		for(i = 2; i <= n; i++)
			if(con[i] && r) {
				r--; num_comps++;
				dfs(i);
				con[i] = 0;
				g2[i].pb(1); g2[1].pb(i);
				// cout << i << " " << 1 << endl;
			}

		// for(i = 1; i <= n; i++)
		// 	if(r && con[i]) {
		// 		r--, g2[i].pb(1), g2[1].pb(i);
		// 		cout << i << " " << 1 << endl;
		// 	}
			
		// cout << endl;

		// bfs();

		// for(auto it : ansv) cout << it.f << " " << it.s << endl;

		return 0;
	}