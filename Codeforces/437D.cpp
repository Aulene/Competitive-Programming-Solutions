#include <bits/stdc++.h>
#include <unordered_map>

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
#define vpi vector < pair <int, int> > 
#define mid (start + end) / 2
#define pi pair <int, int>

const int N = 100007;
vector <int> path;
vector < vector <int> > cycles;
int vis[N], a[N];
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


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
        int n, m, i, j, u, v, w, h;

		cin >> n >> m;

		for(i = 1; i <= n; i++) cin >> a[i];

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
		}

		dfs(1);

		for(auto it : cycles) {
			for(auto it2: it) cout << it2 << " "; cout << endl;
		}

		return 0;
	}