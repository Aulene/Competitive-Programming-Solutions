#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
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

const int N = 300007;

vvi g(N);
int col[N];

int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m, b >>= 1;
	return res;
}

int bipartite(int x) {
	queue <int> q;
	q.p(x);

	col[x] = 1;

	int b = 1, w = 0;

	while(!q.empty()) {

		x = q.front(); q.pop();

		for(auto it : g[x]) {
			if(col[it] == 0) {
				if(col[x] == 1) col[it] = 2, w++;
				else col[it] = 1, b++;
				q.p(it);
			}
			else if(col[it] == col[x]) return 0;
		}
	}

	int ans = (powmod(2, b, mod) % mod + powmod(2, w, mod) % mod) % mod;
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
		
		int t, n, m, i, j, u, v, ans;

		cin >> t;

		while(t--) {

			for(i = 0; i <= n; i++) {
				col[i] = 0;
				g[i].clear();
			}
			
			int ansx = 1;
			ans = 1;

			cin >> n >> m;

			for(i = 0; i < m; i++) {
				cin >> u >> v;
				g[u].pb(v), g[v].pb(u);
			}

			for(i = 1; i <= n; i++)
				if(col[i] == 0) {
					u = bipartite(i);
					ansx = min(ansx, u);
					ans = (ans * u) % mod;
				}

			if(!ansx) ans = 0;

			cout << ans << endl;
		}
		return 0;
	}