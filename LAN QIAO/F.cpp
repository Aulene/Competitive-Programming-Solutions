#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long int
#define mod 998244353
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

const int N = 307;
vector <int> path;
vector < vector <int> > cycles;
int vis[N], wt[N][N], rch[N][N], cycle[N][N], con[N];
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

int powll(int b, int p, int m)
{
	if(!p)
		return 1;
	if(p == 1)
		return b % m;
	
	int x = powll(b, p / 2, m) % m;
	x = (x * x) % m;
	if(p & 1)
		x = (x * (b % m)) % m;
	return x % m;
}
 
int inverse(int a, int m)
{
	return powll(a, m-2, m);
}

void dfs2(int idx, int p = -1) {
	if(con[idx]) return;
	con[idx] = 1;
	for(auto it : g[idx]) 
		if(it != p) dfs2(it, idx);
}

int connected(int n) {
	dfs2(1);
	for(int i = 1; i <= n; i++) if(con[i] == 0) return 0;
	return 1;

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
		
		int n, m, i, j, u, v, w, sum = 0, num = 1;

		cin >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v >> w;
			wt[u][v] = wt[v][u] = w;
			rch[u][v] = 1;
			g[u].pb(v), g[v].pb(u);
		}	

		if(!connected(n)) {
			cout << 0 << endl;
			return 0;
		}

		if(m == n - 1) {

			sum = 1;
			for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++)
				if(rch[i][j] == 1 && !cycle[i][j]) 
					sum = (sum * wt[i][j]) % mod;
			}

			cout << sum << endl;
			return 0;
		}

		dfs(1);

		// for(i = 0; i < cycles.size(); i++)
		// 	if(cycles[i].size() > 2) {
		// 		for(j = 0; j < cycles[i].size(); j++)
		// 			cout << cycles[i][j] << " "; 
		// 		cout << endl;
		// 	}

		for(i = 0; i < cycles.size(); i++)
			if(cycles[i].size() > 2) 
				{
					for(j = 0; j < cycles[i].size() - 1; j++) {
						int u = cycles[i][j], v = cycles[i][j + 1];
						cycle[u][v] = cycle[v][u] = 1;
					}

					u = cycles[i][cycles[i].size() - 1];
					v = cycles[i][0];
					cycle[u][v] = cycle[v][u] = 1;
				}

		// for(i = 1; i <= n; i++)  {
		// 	for(j = 1; j <= n; j++) cout << cycle[i][j] << " "; cout << endl;
		// }

		for(i = 0; i < cycles.size(); i++)
			if(cycles[i].size() > 2) {

				// cout << cycles[i].size() << endl;

				int csum = 0;

				int cprod = 1;
				for(j = 0; j < cycles[i].size() - 1; j++) {
					int u = cycles[i][j], v = cycles[i][j + 1];
					cprod = (cprod * wt[u][v]) % mod;
				}

				u = cycles[i][cycles[i].size() - 1];
				v = cycles[i][0];
				cprod = (cprod * wt[u][v]) % mod;
				
				for(j = 0; j < cycles[i].size() - 1; j++) {
					int u = cycles[i][j], v = cycles[i][j + 1];
					int ad = (cprod * inverse(wt[u][v], mod)) % mod;
					csum = (csum + ad) % mod;
				}

				u = cycles[i][cycles[i].size() - 1];
				v = cycles[i][0];
				int ad = (cprod * inverse(wt[u][v], mod)) % mod;
				csum = (csum + ad) % mod;
				
				sum = (sum + csum) % mod;
				num = (num * cycles[i].size()) % mod;
			}
		
		// cout << sum << endl;

		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++)
				if(rch[i][j] == 1 && !cycle[i][j]) 
					sum = (sum * wt[i][j]) % mod;
		}

		// cout << sum << " " << num << endl;

		int ans = (sum * inverse(num, mod)) % mod;
		cout << ans << endl;

		return 0;
	}