#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define mid (start + end) / 2
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int >

const int N = 300007;

int vis[N], lk[N], sz[N], ans[N];
int path[N], dist[N];

pair <int, int> md;
vector < vector <int> > g(N);

void bfs(int idx) {
    int mdist = 0, midx = idx;

    queue <pi> q;

    q.p({idx, 0});
    vi treeNodes, longPath;

    while(!q.empty()) {
        pi pz = q.front();
        q.pop();

        int u = pz.f, v = pz.s;
        if(vis[u]) continue;
        vis[u] = 1;

        if(v > mdist) { mdist = v, midx = u; }

        treeNodes.pb(u);

        for(auto it : g[u]) {
            int vidx = it, vw = 1;
            q.p(mp(vidx, v + vw));
        }
    }
 
    for(auto it : treeNodes)
        vis[it] = 0, path[it] = it;

    q.p({midx, 0});
    mdist = 0;

    while(!q.empty()) {
        pi pz = q.front();
        q.pop();

        int u = pz.f, v = pz.s;
    
        vis[u] = 1;
        dist[u] = v;

        if(v > mdist) { mdist = v, midx = u; }

        for(auto it : g[u]) {
            int vidx = it, vw = 1;

            if(vis[vidx]) continue;

            path[vidx] = u;
            q.p(mp(vidx, v + vw));
        }
    }

    while(true) {
        longPath.pb(midx);
        if(path[midx] == midx) break;
        midx = path[midx];
    }

    int omax = mdist;
    int ret = midx;

	for(auto it : treeNodes) 
		if(it != ret) {
			lk[it] = ret;
			sz[ret]++;
		}

	ans[ret] = mdist;
}

int find(int x) {
	while(x != lk[x]) x = lk[x];
	return x;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
	a = find(a), b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	ans[a] = max(ans[a], (int) (ceil((double) ans[a] / 2) + ceil((double) ans[b] / 2) + 1));
	ans[a] = max(ans[a], ans[b]);
	sz[a] += sz[b];
	lk[b] = a;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
        cout.tie(NULL);

        int n, m, q, i, j, x, u, v, sum;

		for(i = 0; i < N; i++) sz[i] = 1, lk[i] = i, ans[i] = 0;

		cin >> n >> m >> q;

		while(m--) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}
			

		for(i = 1; i <= n; i++)
			if(!vis[i]) bfs(i);

		while(q--) {
			cin >> x;

			if(x == 1) {
				cin >> u;
				u = find(u);
				cout << ans[u] << endl;
			}
			else {
				cin >> u >> v;
				unite(u, v);
				// cout << "ANUS = " << lk[v] << endl;
				// cout << "FUCK = " << ans[lk[v]] << endl;
			}
		}

		return 0;   
	}