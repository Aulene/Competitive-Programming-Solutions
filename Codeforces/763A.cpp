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
#define vpi vector < pair <int, int> >

const int N = 100007;
bool ans = 1;
int col[N];
vvi g(N);
vpi vs;

void dfs(int idx, int p = -1, int cx = -1) {
	if(cx != -1)
		if(col[idx] != cx) ans = 0;

	for(auto v : g[idx]) {
		if(v != p) {
			if(cx == -1) dfs(v, idx, col[v]);
			else dfs(v, idx, cx);
		}
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
		
		int n, m, i, j, u, v;
		bool ansx = 1;
		pair <int, int> fx = zp, zpv = zp;

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			 cin >> u >> v;
			 if(u > v) swap(u, v);
			 g[u].pb(v), g[v].pb(u);
			 vs.pb({u, v});
		}

		for(i = 1; i <= n; i++) cin >> col[i];

		for(auto it : vs) {
			u = it.f, v = it.s;

			if(col[u] != col[v]) {
				if(fx == zpv) fx = mp(u, v);
				else {
					if(fx.f == u || fx.s == u) fx = mp(u, -1);
					else if(fx.f == v || fx.s == v) fx = mp(v, -1);
				}
			}

		}

		// if(!ansx) {
		// 	cout << "NO\n"; return 0;
		// }

		if(fx == zpv) {
			cout << "YES\n1\n";
			return 0;
		}

		u = fx.f, v = fx.s;

		if(u != 0) dfs(u);
		else ans = 0;

		if(ans) {
			cout << "YES\n" << u << "\n";
			return 0;
		}

		ans = 1;
		if(v != 0 && v != -1) dfs(v);
		else ans = 0;

		if(ans) {
			cout << "YES\n" << v << "\n";
			return 0;
		}

		cout << "NO" << endl;


		return 0;
	}