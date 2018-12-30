#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define lli long long int
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

const int N = 5007;

int dp[N][N];
int par[N][N];
vvpi g(N);

void solve() {

	priority_queue < ppi, vector <ppi>, greater <ppi> > pq;
	pq.p({{1, 1}, 0});
	dp[1][1] = 0;

	while(!pq.empty()) {

		ppi pz = pq.top(); pq.pop();

		int u = pz.f.f, dist = pz.f.s;
		lli tm = pz.s;

		// cout << u << " " << dist << " " << tm << endl;

		for(auto it : g[u]) {
			int v = it.f, w = it.s;
			if(dp[v][dist + 1] > tm + w) {
				par[v][dist + 1] = u;
				dp[v][dist + 1] = tm + w;
				pq.p({{v, dist + 1}, tm + w});
			}
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, w, t, ans = 0;

		cin >> n >> m >> t;

		for(i = 1; i <= m; i++) {
			cin >> u >> v >> w;
			g[u].pb({v, w});
		}

		for(i = 1; i <= n; i++) 
			for(j = 1; j <= n; j++) dp[i][j] = INT_MAX;

		solve();

		for(i = 1; i <= n; i++)
			if(dp[n][i] <= t) ans = i;

		vi ansv;

		int idx = n;

		while(idx != 0) {
			ansv.pb(idx);
			idx = par[idx][ans];
			ans--;
		}

		reverse(ansv.begin(), ansv.end());

		cout << ansv.size() << endl;
		for(auto it : ansv) cout << it << " "; cout << endl;
		return 0;
	}