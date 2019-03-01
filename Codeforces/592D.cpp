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

const int N = 130007;

vvi g(N), req_g(N);
int atk[N], incl[N], dist[N];
int edges_x2 = 0, overall_dist = 0, src = -1, ac_src;

int find_nodes(int idx, int p = -1) {
	int ans = 0;
	for(auto it : g[idx])
		if(it != p) ans = max(ans, find_nodes(it, idx)); 
	incl[idx] = (ans | atk[idx]);
	return (atk[idx] | incl[idx]);
}

void build_graph(int n) {
	for(int i = 1; i <= n; i++)
		for(auto it : g[i]) 
			if(incl[i] && incl[it]) req_g[i].pb(it), edges_x2++;
}

int get_src(int n) {
	for(int i = 1; i <= n; i++)
		if(incl[i]) return i;
}

void max_dist(int idx, int p = -1) {
	if(p == -1) dist[idx] = 0;
	else dist[idx] = dist[p] + 1;

	for(auto it : req_g[idx])
		if(it != p) max_dist(it, idx);
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
		
		int n, m, i, j, u, v, ans;

		cin >> n >> m;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
		}

		for(i = 0; i < m; i++) {
			cin >> u, atk[u] = 1;
			if(src == -1) src = u;
		}

		find_nodes(src);
		build_graph(n);
		src = get_src(n);

		max_dist(src);
		for(i = 1; i <= n; i++) overall_dist = max(overall_dist, dist[i]);

		// madarchod kitna adhik chutiyapa hai ye
		
		for(i = 1; i <= n; i++) 
			if(incl[i] && dist[i] == overall_dist) 
				{
					max_dist(i);
					overall_dist = 0;
					for(j = 1; j <= n; j++)
						overall_dist = max(overall_dist, dist[j]);
					
					for(j = 1; j <= n; j++)
						if(incl[j] && dist[j] == overall_dist) {
							ac_src = min(i, j);
							break;
						}
					break;
				}

		ans = edges_x2 - overall_dist;
		cout << ac_src << endl << ans << endl;

		return 0;
	}