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
#define MOD 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

const int N = 100007;

vvpi g(N);
int is_gate[N];
int vis[N];

int dijkstra(int n) {

	priority_queue < pi, vpi, greater < pi > > pq;

	REP(i, n) 
		if(is_gate[i]) vis[i] = 1, pq.p({0, i});

	while(!pq.empty()) {
		pi pz = pq.top(); pq.pop();
		int u = pz.s, d = pz.f;

		// printf("u: %d dist: %d vis: %d\n", u, d, vis[u]);

		if(vis[u] == 0) {
			// printf("%d is now 1\n", u);
			vis[u] = 1;
			continue;
		}
		if(vis[u] == 2) continue;
		if(u == 0) return d;
		vis[u] = 2;

		for(auto it : g[u]) {
			int v = it.f, w = it.s;
			if(vis[v] == 2) continue;
			// printf("push v: %d dist: %d\n", v, d + w);
			pq.p({d + w, v});
		}
	}

	return 0;
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
		
		int n, m, k, i, j, u, v, w;

		cin >> n >> m >> k;

		REP(i, m) {
			cin >> u >> v >> w;
			g[u].pb({v, w}); g[v].pb({u, w});
		}
		
		REP(i, k) cin >> u, is_gate[u] = 1;

		cout << endl;

		cout << dijkstra(n) << endl;

		return 0;
	}

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
