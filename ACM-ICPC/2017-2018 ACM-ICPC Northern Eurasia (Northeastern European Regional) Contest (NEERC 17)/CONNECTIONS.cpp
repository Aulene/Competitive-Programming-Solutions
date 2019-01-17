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

const int N = 100007;

int n; // number of nodes
vector<vector<int>> g(N); 

vector<bool> visited;
vector<int> tin, fup;
int timer;
map < pi, int> mx;

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
                mx[{v, to}] = 1;
        }
}
}

void find_bridges() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    fup.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if(!visited[i]) dfs(i);
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
		
		int m, i, j, u, v, t, T;

		cin >> T;

		for(t = 1; t <= T; t++) {

			for(auto it : g) it.clear();
			g.clear();

			cin >> n >> m;

			for(i = 0; i < m; i++) {
				cin >> u >> v;
				u--, v--;
				g[u].pb(v);
			}

			find_bridges();

			for(auto it : mx) 
				cout << it.f.f << " " << it.f.s << endl;

		}
		return 0;
	}