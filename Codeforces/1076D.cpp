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
int p[N], d[N], vis[N], ec[N];

vi ansv;
vvi g(N);
vvpi g2(N);
vector <ppipi> vs;
map < pair <int, int>, int> mx;

bool cmp(ppipi a, ppipi b) { return a.s.f < b.s.f; }

// int find(int x) {
//     while(x != lk[x]) x = lk[x];
//     return x;
// }

// bool same(int a, int b) { return find(a) == find(b); }

// int unite(int a, int b) {
//     a = find(a), b = find(b);
//     if(same(a, b)) return 0;
//     if(sz[a] < sz[b]) swap(a, b);
//     sz[a] += sz[b];
//     lk[b] = a;
//     return 1;
// }

// int dfs(int idx, int p = -1) {
//     for(auto it : g[idx])
//         if(it != p) dfs(it, idx);
    
//     if(p != -1) ansv.pb(mx[{idx, p}]);
// }

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

void dijkstras(int n)
{
    for(int i = 2; i < N; i++) d[i] = INT_MAX;

    priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > q;
    
    p[1] = 0;
    q.p({1, d[1]});

    while(!q.empty()) {

        pi pz = q.top();
        q.pop();

        int u = pz.f, v = pz.s;

        for(auto it : g2[u])
            if(d[it.f] > v + it.s) {
                d[it.f] = v + it.s;
                p[it.f] = u;
                ec[it.f] = 1;
                ec[u] = 0;
                q.p({it.f, d[it.f]});
            }
    }

    // for(int i = 1; i <= n; i++) cout << p[i] << " "; cout << endl;
    // for(int i = 1; i <= n; i++) cout << d[i] << " "; cout << endl;

    for(int i = 1; i <= n; i++)
        if(ec[i]) {
            int x = i;
            
            while(p[x] != 0) {
                
                g[x].pb(p[x]);
                g[p[x]].pb(x);
                
                // cout << x << " " << p[x] << endl;
                x = p[x];
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
            mx[{u, v}] = mx[{v, u}] = i;
            g2[u].pb({v, w}), g2[v].pb({u, w});
        }

        dijkstras(n);
        bfs(k);

        cout << ansv.size() << endl;
        for(auto it : ansv) cout << it + 1 << " "; cout << endl;
        return 0;
    }