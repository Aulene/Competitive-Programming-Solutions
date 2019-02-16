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

vvi g(N);

priority_queue < int, vi, greater <int> > pq;
vi ansv;

int vis[N];

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
		
		int n, m, i, j, u, v, w;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		for(i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());

		pq.p(1);

		while(!pq.empty()) {
			u = pq.top(); pq.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			ansv.pb(u);
			for(auto it : g[u]) 
				if(!vis[it]) pq.p(it);
		}

		for(auto it : ansv) cout << it << " "; cout << endl;

		return 0;
	}