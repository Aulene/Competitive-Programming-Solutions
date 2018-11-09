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
#define zp mp(0, 0)

const int N = 200007;
const int LogN = 20;

vector < vector < pi > > g(N);
vector <ppi> vs, vs1, mst;

int lk[N], sz[N];
int tin[N], tout[N];
int up[N][LogN + 7], wt[N][LogN + 7];
int timer = 1;

void dfs(int idx, int p = 1, int w = 0) {
	
	tin[idx] = timer++;
	up[idx][0] = p;
	wt[idx][0] = w;

	for(int i = 1; i <= LogN; i++) {
		up[idx][i] = up[up[idx][i - 1]][i - 1];
		wt[idx][i] = max(wt[idx][i - 1], wt[up[idx][i - 1]][i - 1]);
	}

	for(auto it : g[idx])
		if(it.f != p) dfs(it.f, idx, it.s);

	tout[idx] = timer++;
}

bool ancestor(int u, int v) {
	if(tin[u] <= tin[v] && tout[u] >= tout[v]) return true;
	return false;
}

int lca(int u, int v) {
	if(ancestor(u, v)) return u;
	if(ancestor(v, u)) return v;

	for(int i = LogN; i >= 0; i--)
		if(!ancestor(up[u][i], v)) u = up[u][i];

	return up[u][0];
}

int lcawt(int u, int v, int lca) {
	int answt = 0;
	int ux = u;

	for(int i = LogN; i >= 0; i--)
		if(!ancestor(up[u][i], v)) {
			// cout << u << " " << i << " " << wt[u][i] << endl;
			answt = max(answt, wt[u][i]);
			u = up[u][i];
		}
	
	if(up[u][0] == lca)
		answt = max(answt, wt[u][0]);

	u = ux;

	for(int i = LogN; i >= 0; i--)
		if(!ancestor(up[v][i], u)) {
			// cout << v << " " << i << " " << wt[v][i] << endl;
			answt = max(answt, wt[v][i]);
			v = up[v][i];
		}

	if(up[v][0] == lca)
		answt = max(answt, wt[v][0]);
	return answt;
}

int find(int idx) {
	while(idx != lk[idx]) idx = lk[idx];
	return idx;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
	a = find(a), b = find(b);
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	lk[b] = a;
}

bool cmp(ppi a, ppi b) { return a.s < b.s; }

int kruskals(int n) {
	int ans = 0;

	for(auto it : vs) {
		int u = it.f.f, v = it.f.s, w = it.s;

		if(!same(u, v)) {
			unite(u, v);
			mst.pb(it);
			ans += w;
		}
	}

	return ans;
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

		int n, m, i, j, u, v, w, ans;

		for(i = 0; i < N; i++) lk[i] = i, sz[i] = 1;
		
		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v >> w;
			vs.pb({{u, v}, w});
			vs1.pb({{u, v}, w});
		}

		sort(vs.begin(), vs.end(), cmp);

		int mstwt = kruskals(n);

		// cout << endl;
		// cout << "MST Size = " << kruskals(n) << endl;
		// for(auto it : mst) cout << it.f.f << " " << it.f.s << endl;
		// cout << endl;
		
		for(auto it : mst) {
			int u = it.f.f, v = it.f.s, w = it.s;
			g[u].pb({v, w});
			g[v].pb({u, w});
		}

		dfs(1);

		// for(int i = 1; i <= n; i++) cout << tin[i] << " "; cout << endl;
		// for(int i = 1; i <= n; i++) cout << tout[i] << " "; cout << endl;

		// cout << endl;
		// for(int i = 1; i <= n; i++) 
		// 		{ for(int j = 0; j <= LogN; j++) cout << up[i][j] << " "; cout << endl; }
		// cout << endl;

		// cout << endl;
		// for(int i = 1; i <= n; i++) 
		// 		{ for(int j = 0; j <= LogN; j++) cout << wt[i][j] << " "; cout << endl; }
		// cout << endl;
			
		for(auto it : vs1) {
			u = it.f.f, v = it.f.s;
			ans = mstwt - lcawt(u, v, lca(u, v)) + it.s;
			cout << ans << endl;
		}

		return 0;
	}