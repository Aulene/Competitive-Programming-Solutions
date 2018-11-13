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

int p[N], d[N], vis[N], ec[N], nz[N];

vi ansv;
vvpi g2(N);
map < pair <int, int>, int> mx;

void dijkstras(int n, int k)
{
    for(int i = 1; i < N; i++) d[i] = LLONG_MAX, p[i] = -1;

    set < pair <int, int> > q;
    
    d[1] = 0;
    q.insert({0, 1});

    while(!q.empty() && ansv.size() < k) {

        pi pz = *q.begin();
        q.erase(q.begin());

        int v = pz.f, u = pz.s;
        
        if(ansv.size() >= k) return;
        if(p[u] != -1) ansv.pb(p[u]);
            
        for(auto it : g2[u])
            if(d[it.f] > v + it.s) {
                
                q.erase({d[it.f], it.f});
                d[it.f] = v + it.s;
                q.insert({d[it.f], it.f});

                p[it.f] = mx[{u, it.f}];

            }
    }
}

signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, k, i, j, u, v, w;

        cin >> n >> m >> k;

        for(i = 0; i < m; i++) {
            cin >> u >> v >> w;
            mx[{u, v}] = mx[{v, u}] = i + 1;
            g2[u].pb({v, w}), g2[v].pb({u, w});
        }

        dijkstras(n, k);

        cout << ansv.size() << endl;
        for(auto it : ansv) cout << it << " "; cout << endl;
        return 0;
    }