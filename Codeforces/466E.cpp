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
#define vvpi vector < vector < pair <int, int> > > 
#define vppi vector < pair < int, pair <int, int> > > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 100007;

int in[N], out[N], h[N];
int lk[N], sz[N];
int ans[N];
int t = 1;

vvpi packs(N);
vvi g(N);
vppi vs;

void dfs(int idx) {
	in[idx] = t++;
	for(auto it : g[idx]) dfs(it);
	out[idx] = t++;
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

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		int n, m, i, j, q, u, v, packets = 1, queries = 1;
		int x, y;

		cin >> n >> m;

		for(i = 0; i < N; i++) lk[i] = i;
		for(i = 0; i < N; i++) sz[i] = 1;
		for(i = 0; i < N; i++) h[i] = 1;

		for(i = 0; i < m; i++) {
			u = v = q = -1;

			cin >> q;

			if(q == 1) {
				cin >> u >> v;
				h[u] = 0;
				g[v].pb(u);
			}
			else if(q == 2) cin >> u;
			else {
				cin >> u >> v;
				// cout << "PACKET = " << v << " TO PERSON = " << u << " QUERYNO = " << queries << endl;  
				packs[v].pb({u, queries++});
			}

			vs.pb({q, {u, v}});
		}

		for(i = 1; i <= n; i++)
			if(h[i]) dfs(i);

		// for(i = 1; i <= n; i++) 
		// 	if(h[i]) cout << i << " "; cout << endl;

		// for(i = 1; i <= n; i++) cout << in[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << out[i] << " "; cout << endl;


		for(i = 0; i < m; i++) {

			int q = vs[i].f, u = vs[i].s.f, v = vs[i].s.s;

			if(q == 1) {
				unite(u, v);
			}
			else if(q == 2) {

				// cout << "CHECKING PACKET = " << packets << endl;

				for(auto it: packs[packets]) {
					x = it.f, y = it.s;
					if(same(u, x) && (in[x] <= in[u]) && (out[x] >= out[u])) 
						ans[y] = 1;
				}

				packets++;
			}
		}

		for(i = 1; i < queries; i++)
			if(ans[i]) cout << "YES\n";
			else cout << "NO\n";
		
		return 0;
	}