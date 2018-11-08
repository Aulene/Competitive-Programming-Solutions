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

vector < vector < pi > > g(N);
vector <ppi> vs;

int lk[N], sz[N];

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

		int n, m, i, j, u, v, w;

		for(i = 0; i < N; i++) lk[i] = i, sz[i] = 1;
		
		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v >> w;
			g[u].pb({v, w});
			g[v].pb({u, w});
			vs.pb({{u, v}, w});
		}

		sort(vs.begin(), vs.end(), cmp);

		cout << kruskals(n) << endl;

		return 0;
	}