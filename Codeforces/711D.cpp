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

const int N = 200007;

int n;
vector < vector <int> > g(N);
vector <char> color;
vector <int> parent;
vvi cycles;
int cycle_start, cycle_end;

bool dfs(int v) {
    color[v] = 1;
    
    for(int u : g[v]) {
        if(color[u] == 0) {
            parent[u] = v;
            if(dfs(u)) return true;
        } 
        else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }

    color[v] = 2;
    return false;
}

vi find_cycle() {
    color.assign(n + 1, 0);
    parent.assign(n + 1, -1);
    cycle_start = -1;

    vi cycle;

    for(int v = 1; v <= n; v++) {

        if(!color[v]) {

        	if(dfs(v)) {
        		cycle.push_back(cycle_start);
			    for(int v = cycle_end; v != cycle_start; v = parent[v]) cycle.push_back(v);
			    cycle.push_back(cycle_start);
			    reverse(cycle.begin(), cycle.end());
        	}

        	cycles.pb(cycle);
        	cycle.clear();
        	cycle_start = -1;
        }

    }

    return cycle;
}

int fact[N];

void facts() {
	fact[0] = 1;
	for(int i = 1; i < N; i++) fact[i] = (fact[i - 1] * i) % mod;
}

int powmod(int a, int b, int m) {
	int res = 1;
	while(b)
		if(b & 1) res = (res * 1ll * a) % m, --b;
		else a = (a * 1ll * a) % m,  b >>= 1;
	return res;
}

int inv(int a, int m) { return a < 2 ? a : ((1 - m * 1ll * inv(m % a, a)) / a % m + m) % m; }

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
		
		facts();

		int m, i, j, u, v = 0, ans = 1;
		vi cycle;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> u, g[i].pb(u);

		cycle = find_cycle();
        
        // for(auto it : cycle) cout << it << " "; cout << endl;
        
        for(auto it : cycles) {
        	// for(auto it2 : it) cout << it2 << " "; cout << endl;
        	
        	m = it.size() - 2;
        	v += m;

			int sum = 0;

			for(j = 1; j <= m; j++) {

				int num = fact[m] % mod;
				int den1 = inv(fact[j], mod) % mod;
				int den2 = inv(fact[m - j], mod) % mod;

				num = (num * den1) % mod;
				num = (num * den2) % mod;
				sum = (sum + num) % mod;
			}

			// cout << sum << endl;

			if(sum) ans = (ans * sum) % mod;
        }

		ans = (ans * powmod(2, n - v, mod) % mod) % mod;

		cout << ans << endl;

		return 0;
	}