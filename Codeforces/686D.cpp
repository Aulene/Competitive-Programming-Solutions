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

const int N = 300007;

vvi g(N);
int sz[N], par[N], cent[N];

int dfs(int idx, int p = -1) {
	sz[idx] = 1;
	par[idx] = p;

	for(auto it : g[idx])
		if(it != p) sz[idx] += dfs(it, idx);
	
	int ms = 0, mv = 0;

	for(auto it : g[idx]) 
		if(it != p && sz[it] > ms) {
			ms = sz[it]; mv = it;
		}

	if(sz[idx] <= 2 || (ms < sz[idx] / 2) ) {
		cent[idx] = idx;
	}
	else {
		int l = cent[mv];
		while(sz[l] < (sz[idx] + 1) / 2)
			{ l = par[l]; }
		cent[idx] = l;
	}

	return sz[idx];
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

		for(i = 2; i <= n; i++) {
			cin >> u;
			g[i].pb(u), g[u].pb(i);
		}

		dfs(1);

		// for(i = 1; i <= n; i++) cout << sz[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << cent[i] << " "; cout << endl;

		while(m--) { cin >> u; cout << cent[u] << endl; }
		
		return 0;
	}