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

int deg[N], vis[N];
vvi g(N);

vpi ansv;

int mdeg = 0, vert;

void fuck(int idx) {
	queue < pi > q;
	q.p({idx, -1}); vis[idx] = 1;
	while(!q.empty()) {
		pi pz = q.front(); q.pop();
		int i = pz.f, p = pz.s;
		for(auto it : g[i])
			if(!vis[it]) ansv.pb({i, it}), q.p({it, i}), vis[it] = 1;
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
	
		int n, m, i, j, u, v;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
			deg[u]++, deg[v]++;
			if(mdeg < deg[u]) mdeg = deg[u], vert = u;
			if(mdeg < deg[v]) mdeg = deg[v], vert = v;
		}
		
		fuck(vert);
		for(auto it : ansv) cout << it.f << " " << it.s << endl;

		return 0;
	}