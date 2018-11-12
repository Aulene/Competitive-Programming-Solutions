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

const int N = 100007;

vvpi g(N);

int num[N], down[N], up[N];

int lucky(int n) {
    while(n) {
        int x = n % 10;
        if((x != 4) && (x != 7)) return 0;
        n /= 10;
    }
    return 1;
}

void dfs(int idx, int p = -1, int w = 0) {
    num[idx] = 1;

    for(auto it : g[idx])
        if(it.f != p) {
            dfs(it.f, idx, it.s);

            num[idx] += num[it.f];

            if(it.s == 1) down[idx] += num[it.f];
            else down[idx] += down[it.f];
        }
} 

void dfs2(int n, int idx, int p = -1, int w = 0) {
    
    if(p != -1) {
        if(w == 1) up[idx] = n - num[idx];
        else up[idx] = down[p] - down[idx] + up[p];
    }

    for(auto it : g[idx]) 
        if(it.f != p) dfs2(n, it.f, idx, it.s);
}

int compute(int a, int b) { return (a * (a - 1)) + (b * (b - 1)) + 2 * a * b; }

signed main()                                                                                                                                                                         
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n, m, i, j, u, v, w, ans = 0;
       
        cin >> n;

        for(i = 0; i < n - 1; i++) {
            cin >> u >> v >> w;
            w = lucky(w);
            // cout << u << " " << v << " " << w << endl;
            g[u].pb({v, w}), g[v].pb({u, w});
        }
        
        dfs(1);
        dfs2(n, 1);

        // cout << "nm[]: "; for(i = 1; i <= n; i++) cout << num[i] << " "; cout << endl;
        // cout << "dn[]: "; for(i = 1; i <= n; i++) cout << down[i] << " "; cout << endl;
        // cout << "up[]: "; for(i = 1; i <= n; i++) cout << up[i] << " "; cout << endl;

        for(i = 1; i <= n; i++) ans += compute(down[i], up[i]);
        
        cout << ans << endl;

        return 0;
    }