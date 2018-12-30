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

const int N = 300007;

int n, ans = 0;

vvi g(N);
vvi bt(N);

int st = -1;

vector<bool> visited(N);
vi tin, fup;
int timer;

vector <int> a[N];
bool vx[N];
int dist[N];
queue<int> q;

int bfs(int start)
{
    int i, v;
 
    memset(dist, 0, sizeof(dist));
    memset(vx, 0, sizeof(vx));
 
    vx[start]=1;
    q.push(start);
 
    while(!q.empty())
        {
            v=q.front();
            q.pop();
 
            for(i=0; i<a[v].size(); i++)
                if(!vx[a[v][i]])
                    {
                        vx[a[v][i]]=1;
                        dist[a[v][i]]=dist[v]+1;
                        q.push(a[v][i]);
                    }
        }
 
    return 0;
}

void IS_BRIDGE(int u, int v) {
    cout << u << " " << v << endl;
    a[u].pb(v), a[v].pb(u);
    if(st == -1) st = u;
}

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = fup[v] = timer++;
    for (int to : g[v]) {
        if (to == p) continue;
        if (visited[to]) {
            fup[v] = min(fup[v], tin[to]);
        } else {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v])
                IS_BRIDGE(v, to);
        }
    }
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    fup.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
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
        
        // ifstream cin ("usaco.in");
        // ofstream cout ("usaco.out");
        
        int m, i, j, u, v;

        cin >> n >> m;

        for(i = 1; i <= m; i++) {
            cin >> u >> v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);
        }

        find_bridges();

        if(st != -1) {
            bfs(st);
     
            int nodeDis=0, maxDis=0, maxNode;
            for(j=0; j<n; j++)
                {
                    nodeDis=dist[j];
                    if(nodeDis>maxDis)
                        {
                            maxDis=nodeDis;
                            maxNode=j;
                        }
                }
         
            bfs(maxNode);
         
            maxDis=0;
            for(j=1; j<=n; j++)
                maxDis=max(dist[j], maxDis);
            ans = maxDis;
        }

        cout << ans << endl;
        return 0;
    }