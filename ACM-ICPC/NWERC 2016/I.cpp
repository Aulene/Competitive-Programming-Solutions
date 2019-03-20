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
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

#define ld long double

const int N = 100007;

int iron[N], coal[N];
int iron_dist[N], coal_dist[N], src_dist[N];
vvpi g1(N), g2(N);
// n + 1 = iron
// n + 2 = coal

void dijkstras(int src, int n) {

	priority_queue <pi, vpi, greater <pi> > pq;
	int *dist;

	if(src == n + 1) dist = iron_dist;
	else if(src == n + 2) dist = coal_dist;
	else dist = src_dist;

	for(int i = 0; i < N; i++) dist[i] = INT_MAX;
	dist[src] = 0;
	
	vvpi g;

	pq.p({src, dist[src]});

	if(src > n) g = g2;
	else g = g1;

	while(!pq.empty()) {

		pi pz = pq.top(); pq.pop();
		int idx = pz.f, w = pz.s;

		for(auto it : g[idx]) {
			if(dist[it.f] > w + it.s) {
				dist[it.f] = dist[idx] + it.s;
				pq.p({it.f, dist[it.f]});
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
		
		int n, m, i, j, u, v, k, num;

		cin >> n >> m >> k;

		for(i = 0; i < m; i++) cin >> u, iron[u] = 1;
		for(i = 0; i < k; i++) cin >> u, coal[u] = 1;
		
		for(i = 1; i <= n; i++) {
			cin >> num;
			for(j = 0; j < num; j++) {
				cin >> u;
				g1[i].pb({u, 1});
				g2[u].pb({i, 1});
			}
		}

		for(i = 1; i <= n; i++)
			if(iron[i]) g1[i].pb({n + 1, 0}), g2[n + 1].pb({i, 0});
		for(i = 1; i <= n; i++)
			if(coal[i]) g1[i].pb({n + 2, 0}), g2[n + 2].pb({i, 0});

		dijkstras(n + 1, n); dijkstras(n + 2, n); dijkstras(1, n);

		// for(i = 1; i <= n; i++) cout << iron_dist[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << coal_dist[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << src_dist[i] << " "; cout << endl;
		int ans = INT_MAX;

		for(i = 1; i <= n; i++) ans = min(ans, iron_dist[i] + coal_dist[i] + src_dist[i]);

		if(ans < INT_MAX) cout << ans << endl;
		else cout << "impossible\n";
		
		return 0;
	}