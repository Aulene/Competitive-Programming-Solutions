#include <bits/stdc++.h>

using namespace std;

#define int long long int
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int>
#define vi vector <int> 
#define vpi vector < pi >
#define vvpi vector < vpi >
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second

const int N = 100007;

vpi vs;
vvpi g(N);
int ans = 0;
bool vis[N];
int path[N], dist[N];

pi bfs(int idx) {

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
            int vidx = it.f, vw = it.s;
            q.p(mp(vidx, v + vw));
        }
    }

    // cout << idx << " " << midx << endl;
    // for(auto it : treeNodes) cout << it << " "; cout << endl;
 
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
            int vidx = it.f, vw = it.s;

            if(vis[vidx]) continue;

            path[vidx] = u;
            q.p(mp(vidx, v + vw));
        }
    }

    // cout << "End Node = " << midx << endl;

    while(true) {
        // cout << midx << " " << path[midx] << " " << dist[midx] << endl;
        longPath.pb(midx);
        if(path[midx] == midx) break;
        midx = path[midx];
    }

    int omax = mdist;
    int ret = midx;

    // cout << "Longest Path\n";
    // for(auto it : longPath) cout << it << " "; cout << endl;

    for(auto it : longPath) {
        int dmax = max(dist[it], abs(mdist - dist[it]));
        if(dmax < omax) {
            omax = dmax;
            ret = it;
        }
    }

    // cout << "Returning " << ret << " Dist = " << omax << endl;
    ans = max(ans, mdist);
    pi pz = mp(ret, omax);
    return pz;
}

bool cmp(pi a, pi b) { return a.s > b.s; }

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // ifstream cin ("/Users/Aulene/Desktop/input.txt");
    // ofstream cout ("/Users/Aulene/Desktop/output.txt");

    // ifstream cin ("input.txt");
    // ofstream cout ("output.txt");

    int n, m, k, i, j, u, v, w;

    cin >> n >> m >> k;

    for(i = 0; i < m; i++) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    for(i = 0; i < n; i++) vis[i] = 0;

    for(i = 0; i < n; i++) {
        if(!vis[i]) {
            pi pz = bfs(i);
            vs.pb(pz);
        }
    }

    // for(auto it : vs) cout << it.f << " " << it.s << endl;
    sort(vs.begin(), vs.end(), cmp);
    // for(auto it : vs) cout << it.f << " " << it.s << endl;

    if(vs.size() <= 1) { ans = max(ans, vs[0].s); }
    else { 
        ans = max(ans, vs[0].s + vs[1].s + k); 
        for(i = 2; i < vs.size(); i++) ans = max(ans, vs[1].s + 2 * k + vs[i].s);
    }

    cout << ans << endl;
    return 0;    
}