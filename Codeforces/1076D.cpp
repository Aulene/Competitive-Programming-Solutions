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
#define pi pair <int, int>
#define vvi vector < vector <int> >
#define vpi vector < pair <int, int> >
#define ppi pair < pair <int, int>, int>
#define ppipi pair <pi, pi> 
#define vvpi vector < vector < pair <int, int> > >
#define zp mp(0, 0)

const int N = 300007;

int lk[N], sz[N];

vi ansv;
vvi g(N);
vector <ppipi> vs;
map < pair <int, int>, int> mx;

bool cmp(ppipi a, ppipi b) { return a.s.f < b.s.f; }

int find(int x) {
    while(x != lk[x]) x = lk[x];
    return x;
}

bool same(int a, int b) { return find(a) == find(b); }

int unite(int a, int b) {
    a = find(a), b = find(b);
    if(same(a, b)) return 0;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    lk[b] = a;
    return 1;
}

int dfs(int idx, int p = -1) {
    for(auto it : g[idx])
        if(it != p) dfs(it, idx);
    
    if(p != -1) ansv.pb(mx[{idx, p}]);
}

void bfs(int k) {
    queue < pair <int, int> > q;
    q.p({1, -1});

    while(!q.empty()) {
        int u = q.front().f, p = q.front().s;
        q.pop();

        for(auto it : g[u])
            if(it != p) {
                if(ansv.size() < k) {
                    ansv.pb(mx[{u, it}]);
                    q.p({it, u});
                }
            }
    }
}

signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for(int i = 0; i < N; i++) lk[i] = i, sz[i] = 1;

        int n, m, k, i, j, u, v, w;

        cin >> n >> m >> k;

        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            vs.pb({{u, v}, {w, i}});
        }

        sort(vs.begin(), vs.end(), cmp);

        for(i = 0; i < m; i++) {
            u = vs[i].f.f, v = vs[i].f.s;
        
            if(unite(u, v)) {
                g[u].pb(v), g[v].pb(u);
                mx[{u, v}] = mx[{v, u}] = vs[i].s.s;
            }
            // else ansv.pb(vs[i].s.s);
        }

        // dfs(1);
        
        // cout << k << endl;
        // i = ansv.size() - 1;
        // while(k--) {
        //     cout << ansv[i] + 1 << " ";
        //     i--;
        // } cout << endl;

        bfs(k);
        cout << ansv.size() << endl;
        for(auto it : ansv) cout << it + 1 << " "; cout << endl;
        return 0;
    }