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
#define mid (start + end) / 2
#define zp mp(0, 0)

const int N = 100007;

vvi g(N);

int is[N], down[N], up[N];

int dfs(int idx, int p = -1) {
	if(is[idx] == 1) down[idx] = 0;
	for(auto it : g[idx])
		if(it != p) down[idx] = max(down[idx], 1 + dfs(it, idx));
	return down[idx];
}

void dfs2(int idx, int p = -1, int d = INT_MIN) {
	up[idx] = d;
	if(is[idx] == 1) up[idx] = max(up[idx], 0LL);

	multiset <int> sx;
	int dx;

	for(auto it : g[idx]) 
		if(it != p) sx.insert(down[it]);

	for(auto it : g[idx]) 
		if(it != p) {
			auto itr = sx.find(down[it]);
			if(itr != sx.end()) sx.erase(itr);
			
			if(sx.size()) dx = max(1 + up[idx], 2 + *sx.rbegin());
			else dx = 1 + up[idx];
			dfs2(it, idx, dx);
			sx.insert(down[it]);
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
		
		int n, m, i, j, u, v, d, ans = 0;

		for(i = 0; i < N; i++) down[i] = up[i] = INT_MIN;
		
		cin >> n >> m >> d;

		for(i = 1; i <= m; i++) { cin >> u; is[u] = 1; }

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		dfs(1);
		dfs2(1);

		// for(i = 1; i <= n; i++) cout << down[i] << " "; cout << endl;
		// for(i = 1; i <= n; i++) cout << up[i] << " "; cout << endl;

		for(i = 1; i <= n; i++) 
			if(up[i] <= d && down[i] <= d) ans++;
		
		cout << ans << endl;

		return 0;
	}