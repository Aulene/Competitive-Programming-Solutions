#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REPD(i, n) for(int i = (n); i >= 0; i--)
#define FORD(i, a, b) for(int i = (a); i >= b; i--)
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))
#define endl '\n'
#define ld long double
#define MOD 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int>
#define vpi vector < pi >
#define ppi pair < pi, int > 
#define vppi vector < pair < pi, int > > 
#define vvpi vector < vector < pi > > 
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

const int N = 2007;
int a[N][N], d[N][N], mx[N][N];
int lk[N], sz[N];

vppi e1, e2;
vvpi g(N);

bool cmp(ppi a, ppi b) { return a.S < b.S; }

void dijkstra(int src) {
	int *dist = d[src];
	
	REP(i, N) dist[i] = INT_MAX;
	dist[src] = 0;

	priority_queue < pi, vpi, greater <pi> > pq;
	pq.p({src, 0});

	while(!pq.empty()) {
		
		pi pz = pq.top(); pq.pop();
		int u = pz.F, ds = pz.S;

		for(auto it : g[u]) {
			int v = it.F, w = it.S;
			if(dist[v] > ds + w) {
				dist[v] = ds + w;
				pq.p({v, dist[v]});
			}
		}
	}
}

int find(int idx) {
	while(idx != lk[idx]) idx = lk[idx];
	return idx;
}

bool same(int a, int b) { return find(a) == find(b); }

void unite(int a, int b) {
	a = find(a), b = find(b);
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	lk[b] = a;
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
				
		int n, m, i, j, u, v;

		while(true) {

			if(scanf("%d", &n) != 1)
				return 0;

			e1.clear(); e2.clear();

			REP(i, N)
				REP(j, N) mx[i][j] = 0;

			REP(i, N) g[i].clear();

			REP(i, N)
				sz[i] = 1, lk[i] = i;

			for(i = 1; i <= n; i++)
				for(j = 1; j <= n; j++) scanf("%d", &a[i][j]);

			for(i = 1; i <= n; i++)
				for(j = i + 1; j <= n; j++) e1.pb({{i, j}, a[i][j]});

			sort(all(e1), cmp);

			for(auto it : e1)
				if(!same(it.F.F, it.F.S)) {
					// cout << it.F.F << " " << it.F.S << " " << it.S << endl;
					e2.pb({{it.F.F, it.F.S}, it.S});
					mx[it.F.F][it.F.S] = mx[it.F.S][it.F.F] = 1;
					g[it.F.F].pb({it.F.S, it.S});
					g[it.F.S].pb({it.F.F, it.S});
					unite(it.F.F, it.F.S);
				}

			FOR(i, 1, n + 1) dijkstra(i);

			// FOR(i, 1, n + 1) {
			// 	FOR(j, 1, n + 1) cout << d[i][j] << " "; cout << endl;
			// }

			int fd = 0;

			FOR(i, 1, n + 1) {
				FOR(j, 1, n + 1)
					if(d[i][j] > a[i][j]) {
						fd = 1;
						e2.pb({{i, j}, d[i][j] - a[i][j]});
						break;
					}
				if(fd) break;
			}

			if(!fd) {
				FOR(i, 1, n + 1) {
					FOR(j, 1, n + 1)
						if(i != j && !mx[i][j]) {
							fd = 1;
							e2.pb({{i, j}, d[i][j]});
							break;
						}
					if(fd) break;
				}
			}
			
			for(auto it : e2) 
				cout << it.F.F << " " << it.F.S << " " << it.S << endl;
			cout << endl;
		}

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
