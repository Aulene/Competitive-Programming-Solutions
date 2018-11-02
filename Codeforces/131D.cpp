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
#define zp mp(0, 0)

const int N = 3007;

vector <int> path;
vector < vector <int> > cycles;
int vis[N], cycle[N], dist[N];
vvi g(N);

void dfs(int v) 
{
    path.push_back(v);
    vis[v] = 1;
    
    for(int i = 0; i < g[v].size(); i++)
	    {
	    	int u = g[v][i];

	    	if(vis[u] != 2) 
			    {
			        if(vis[u] == 1) 
				        {
				            cycles.emplace_back();

				            int id = path.size() - 1;
				            
				            while(path[id] != u)
				                cycles.back().push_back(path[id--]);

				            cycles.back().push_back(u);
				        } 
			        else
			            dfs(u);
			    }
    	}
    

    path.pop_back();
    vis[v] = 2;
}

void dijkstra() {

    priority_queue < pair <int, int>, vector < pair <int, int> >, greater < pair <int, int> > > pq;

    for(int i = 0; i < N; i++) dist[i] = INT_MAX;
    for(int i = 0; i < N; i++)
        if(cycle[i]) dist[i] = 0, pq.p({i, 0});

    while(!pq.empty()) {

        pi pz = pq.top();
        pq.pop();

        int u = pz.f, v = pz.s;

        for(int i = 0; i < g[u].size(); i++) {
            int idx = g[u][i];
            if(dist[idx] > v + 1) {
                pq.p({idx, v + 1});
                dist[idx] = v + 1;
            }
        }
    }     
}
signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);

        int n, m, i, j, u, v;

        cin >> n;

        for(i = 0; i < n; i++) {
            cin >> u >> v;
            g[u].pb(v), g[v].pb(u);
        } 

        dfs(1);

        // for(auto it : cycles) if(it.size() > 2) {
        //     for(auto it2 : it) cout << it2 << " "; cout << endl;
        // }

        for(auto it: cycles) if(it.size() > 2) {
             for(auto it2: it) cycle[it2] = 1;
        }
        
        dijkstra();

        for(int i = 1; i <= n; i++) cout << dist[i] << " "; cout << endl;

  		return 0;  
	}