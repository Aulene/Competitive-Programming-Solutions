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
#define vpi vector < pi >
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int> 
#define zp mp(0, 0)

const int N = 5007;

vvi g(N);
bool vis[N];

int ct = 0;
vi path;

priority_queue < pi, vpi, less < pi > > pq;

void dfs(int idx) {
	if(vis[idx]) return;
	vis[idx] = 1;
	for(auto it : g[idx]) dfs(it);
}

void dfs2(int idx) {
	if(vis[idx]) return;

	ct++;
	vis[idx] = 1;
	path.pb(idx);

	for(auto it : g[idx]) dfs(it);
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
		
		int n, m, i, j, u, v, s, ans = 0;

		cin >> n >> m >> s;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].pb(v);
		}

		dfs(s);
		// cout << endl; for(i = 1; i <= n; i++) cout << i << " " << vis[i] << endl;

		for(i = 1; i <= n; i++) {
			if(!vis[i]) {
				dfs2(i);
				pq.p({i, ct});
				ct = 0;
				for(auto it : path) vis[it] = 0;
				path.clear();
			}
		}

		// cout << endl;

		// for(i = 1; i <= n; i++) cout << vis[i] << " "; cout << endl;

 		while(!pq.empty()) {

			if(!vis[pq.top().f]) {
				ans++;
				dfs(pq.top().f);
			}
			// for(i = 1; i <= n; i++) cout << vis[i] << " "; cout << endl;
			// cout << pq.top().f << " " << pq.top().s << endl;
			pq.pop();
		}

		cout << ans << endl;

		return 0;
	}