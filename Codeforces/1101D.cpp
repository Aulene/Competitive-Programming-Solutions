#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define mod 1000000007
#define int long long int
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

bool prime[N], vis[N];
int a[N], depth[N];

vi vs;
vvpi edges(N);
vvi prime_facts(N);
vvi g(N);
set <int> mn;

int nroot;

void sieve() {
	for(int i = 2; i < N; i++) prime[i] = 1;

	for(int i = 2; i < N; i++) {
		if(prime[i]) {
			vs.pb(i);
			prime_facts[i].pb(i);
			for(int j = i + i; j < N; j += i)
				prime[j] = 0, prime_facts[j].pb(i);
		}
	}
}

void dfs(int idx, int p) {
	vis[idx] = 1;

	depth[idx] = 1 + depth[p];
	if(depth[idx] > depth[nroot]) 
		nroot = idx;

	for(auto it : g[idx])
		if(it != p) dfs(it, idx);
}

int solve(int n) {

	int ans = 0;

	for(auto it : mn)
		if(!vis[it] && a[it] > 1) {
			nroot = it; depth[it] = 0; dfs(it, it);
			// cout << i << " " << nroot << endl;
			depth[nroot] = 0; dfs(nroot, nroot);
			ans = max(ans, depth[nroot]);
		}

	return ans;
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
		
		sieve();

		int n, m, i, j, u, v, ans = 0;

		cin >> n;

		for(i = 1; i <= n; i++) {
			cin >> a[i];
			ans = (a[i] > 1) ? 1 : 0;
		}

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			int gv = gcd(a[u], a[v]);
			// printf("gv = %lld\nfacts = ", gv);
			for(auto it : prime_facts[gv]) {
				// printf("%lld, ", it);
				edges[it].pb({u, v}); 
			}
			// cout << endl;
				
		}

		for(auto it : vs) {
			// cout << "prime = " << it << endl;

			for(auto it : mn) g[it].clear(), vis[it] = 0;
			mn.clear();

			for(auto it2 : edges[it]) {
				u = it2.f, v = it2.s;
				// printf("(%lld,%lld) ", u, v);
				mn.insert(u); mn.insert(v);
				g[u].pb(v), g[v].pb(u);
			}

			// cout << endl;

			ans = max(ans, solve(n));
		}

		cout << ans << endl;

		return 0;
	}