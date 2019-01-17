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

const int N = 100007;

struct edge {
	int u, v, w, idx;
	bool operator<(const edge &y) const { return w > y.w; }
};

edge e[N];
int top[N], color[N];
int white = 0, gray = 1, black = 2, ptr = 1;

vvi g(N);

bool cycle_dfs(int idx) {
	color[idx] = gray;
	for(auto it : g[idx]) {
		if(color[it] == gray) return true;
		if(color[it] == white && cycle_dfs(it)) return true;
	}
	color[idx] = black;
	return false;
}

void topo_dfs(int idx) {
	if(top[idx]) return;
	for(auto it : g[idx]) topo_dfs(it);
	top[idx] = ptr++;
}

void construct_graph(int n, int m) {
	for(int i = 1; i <= n; i++) g[i].clear(), color[i] = white;
	for(int i = 0; i <= m; i++) g[e[i].u].pb(e[i].v);
}


bool isCyclic(int n, int m) {
	construct_graph(n, m);
	bool ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, cycle_dfs(i));
	return ans;
}

int bs(int n, int m) {
	int low = 0, high = m - 1, mid, ans = -1;

	while(low <= high) {
		mid = (low + high) / 2;
		if(isCyclic(n, mid)) {
			high = mid - 1;
		} else {
			ans = mid;
			low = mid + 1;
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
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int n, m, i, j, u, v, w, lidx, ans;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> e[i].u >> e[i].v >> e[i].w;
			e[i].idx = i;
		}

		sort(e, e + m);

		// for(i = 0; i < m; i++) cout << e[i].u << " " << e[i].v << " " << e[i].w << " " << e[i].idx << endl;

		lidx = bs(n, m);
		ans = e[lidx + 1].w;

		construct_graph(n, lidx);
		for(i = 1; i <= n; i++) topo_dfs(i);

		vi ansv;

		for(i = lidx + 1; i < m; i++)
			if(top[e[i].u] < top[e[i].v]) ansv.pb(e[i].idx + 1);

		sort(ansv.begin(), ansv.end());
		cout << ans << " " << ansv.size() << endl;
		for(auto it : ansv) cout << it << " "; cout << endl;

		return 0;
	}