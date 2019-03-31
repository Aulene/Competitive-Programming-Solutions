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

int c[N], p[N];
int cc[N], num_c[N], vis[N];
vvi g(N);
vpi tr;
vi ansv;

bool cmp(pi a, pi b) {
	if(a.s != b.s) return a.s > b.s;
	return a.f < b.f;
}

void get_traversal(int idx) {
	queue <pi> q;
	q.p({idx, 1});
	while(!q.empty()) {
		pi pz = q.front(); q.pop();
		vis[pz.f] = pz.s;
		tr.pb(pz);
		for(auto it : g[pz.f])
			if(vis[it] == 0) q.p({it, pz.s + 1});
	}

	sort(tr.begin(), tr.end(), cmp);
	// reverse(tr.begin(), tr.end());
}

int numc_comp(int idx, int p = -1) {
	int sz = 0;
	for(auto it : g[idx])
		if(it != p) {
			sz += 1;
			numc_comp(it, idx);
		}
	return num_c[idx] = sz;
}

int cc_comp(int idx, int p = -1) {
	int sz = 0 ;
	for(auto it : g[idx]) {
		if(it != p) {
			// cout << idx << " " << it << endl;
			if(c[it] == 1) sz++;
			cc_comp(it, idx);
		}
	}
	return cc[idx] = sz;
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
		
		int n, m, i, j, u, v, root;

		cin >> n;
	
		FOR(i, 1, n) {
			cin >> p[i] >> c[i];
			if(p[i] == -1) root = i;
			else g[i].pb(p[i]), g[p[i]].pb(i);
		}

		FOR(i, 1, n) sort(g[i].begin(), g[i].end());
	
		// FOR(i, 1, n) {
		// 	cout << i << endl;
		// 	for(auto it : g[i]) cout << it << " "; cout << endl;
		// }
		// get_traversal(root);
		
		FOR(i, 1, n) {
			if(c[i] == 1) tr.pb({i, 0});
		}

		numc_comp(root);
		cc_comp(root);
		// FOR(i, 1, n) cout << vis[i] << " "; cout << endl;
		// for(auto it : tr) cout << it.f << " "; cout << endl;
		// FOR(i, 1, n) cout << num_c[i] << " "; cout << endl;
		// FOR(i, 1, n) cout << cc[i] << " "; cout << endl;
		
		for(auto it : tr) {
			int u = it.f;
			if(c[u] == 1 && num_c[u] == cc[u]) ansv.pb(u);
		}

		if(ansv.size() == 0) cout << -1 << endl;
		else {
			for(auto it : ansv) cout << it << " "; cout << endl;
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
