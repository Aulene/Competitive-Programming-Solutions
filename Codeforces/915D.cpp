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

const int N = 507;

int vis[N];
vvi g(N);
int u1, v1;

int n;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    for (int u : g[v]) {
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

vi find_cycle() {
    color.assign(N, 0);
    parent.assign(N, -1);
    cycle_start = -1;

    for(int v = 1; v <= n; v++)
        if(dfs(v)) break;

    vi cycle;

    if(cycle_start == -1) return cycle;
   	else {
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());
        return cycle;
    }
}

int dfs2(int v) {
    color[v] = 1;
    for (int u : g[v]) {
    	if(u == v1 && v == u1) continue;
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs2(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
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
		
		int m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].pb(v);
		}

		vi cycle = find_cycle();

		if(cycle.size()) {
			for(i = 0; i < cycle.size() - 1; i++) {

				color.assign(N, 0);
    			parent.assign(N, -1);
				cycle_start = -1;
				int is = 0;
				u1 = cycle[i], v1 = cycle[i + 1];

				for(j = 1; j <= n; j++) 
					if(dfs2(j)) is = 1;
				if(!is) ans = 1;
			}

			color.assign(N, 0);
   			parent.assign(N, -1);
			cycle_start = -1;
			int is = 0;
			u1 = cycle[cycle.size() - 1], v1 = cycle[0];
			for(j = 1; j <= n; j++)
				if(dfs2(j)) is = 1;
			if(!is) ans = 1;
		}
		else ans = 1;

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;

		return 0;
	}