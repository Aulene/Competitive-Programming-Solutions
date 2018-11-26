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
#define vvpi vector < vector < pair <int, int> > >
#define zp mp(0, 0)

const int N = 300007;

int a[N], sz[N];
int ans[N];

vvi g(N);

int dfs(int idx, int p = -1) {
    int ans = 1;
    for(auto it : g[idx])
        if(it != p) ans += dfs(it, idx);
    return sz[idx] = ans;
}

pi dfs2(int idx, int p = -1) {
    
}

signed main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, i, j, u, v;

        cin >> n >> m;

        for(i = 2; i <= n; i++) {
            cin >> u;
            cout << i << " " << u << endl;
            g[u].pb(i), g[i].pb(u);
        }

        dfs(1);

        for(i = 1; i <= n; i++) cout << sz[i] << " "; cout << endl;

        return 0;
    }