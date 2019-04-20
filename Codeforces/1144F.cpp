#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REPD(i, n) for(int i = (n); i >= 0; i--)
#define FORD(i, a, b) for(int i = (a); i >= b; i--)
#define prArr(a, n) REP(i, n) cout << a[i] << " "; cout << endl;
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))
#define endl '\n'
#define ld long double
#define int long long int
#define MOD 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int>
#define ppi pair < pair <int, int>, int >
#define vpi vector < pi >
#define vvpi vector < vector < pi > > 
#define vppi vector < pair < pi, int > > 
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/*
	Easy mistakes to spot before submitting!
	1. Check const int N (1e5, 2e5).
	2. Check easy cases (n = 1, 2).
	3. Overflows! You'll fuck this up when binary searching.
	4. LONG LONGS! Alternatively, remove the int long long int sometimes.
	5. Check if you're dividing by 0 somewhere.
	6. Memory allocations, sometimes the vector is N^2.
*/

const int N = 200007;

vvi g(N);
map < pi, int > mx, mx2;

int color[N];

bool bipartite_check() {
	queue <int> q;
	color[1] = 1;
	q.p(1);

	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto it : g[u]) 
			if(color[it] == color[u]) return 0;
			else if(color[it] == 0) {
				if(color[u] == 1) color[it] = 2;
				else color[it] = 1;
				q.p(it); 
			}
	}

	return 1;
}

int ans[N], vis[N];

void dfs(int idx, int p = -1, int cnum = 1) {
	vis[idx] = 1;
	for(auto it : g[idx]) {
		if(!vis[it]) {
			if(mx2[{idx, it}] == 1) ans[mx[{idx, it}]] = cnum;
			else ans[mx[{idx, it}]] = !cnum;
			dfs(it, idx, !cnum);
		}
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
		
		int n, m, i, j, u, v, num = 1;

		cin >> n >> m;

		REP(i, m) {
			cin >> u >> v;
			g[u].pb(v), g[v].pb(u);
			mx[{u, v}] = mx[{v, u}] = num++;
			mx2[{u, v}] = 1;
			mx2[{v, u}] = 0;
		}

		if(!bipartite_check()) {
			cout << "NO" << endl;
			return 0;
		}

		dfs(1);
		cout << "YES" << endl;
		for(i = 1; i <= m; i++) cout << ans[i]; cout << endl;
		return 0;
	}

/*
6 5
1 5
2 1
1 4
3 1
6 1
*/

/*
	Snippet Guide - 
	1. Base Conversion - baseconv
	2. Binary Exponentiation (a ^ b % m) - powmod 
	3. Centroid Decomposition - centroid
	4. Code Jam Input - jam
	5. Disjoint Set Union - dsu
	6. Factorial Method - factorials
	7. Factorization O(SqrtN) - factors
	8. Greatest Common Divisor - gcd
	9. Line Template - line
	10. Matrix Exponentiation - matrix
	11. Merge Sort Tree - mstree
	12. Modular Inverse - modinv
	13. Point Template - point
	14. Range Segment Tree (w/ Lazy) - segtree
	15. Range Segment Tree (w/out Lazy) - rstree
	16. Sieve of Eratosthenes - sieve
	17. Topological Sort - toposort
*/
