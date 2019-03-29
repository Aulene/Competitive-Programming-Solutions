#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define REPD(i, n) for(int i = (n); i >= 0; i--)
#define FORD(i, a, b) for(int i = (a); i >= b; i--)
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

const int N = 100007;

int a[N], c[N];
int lk[N], sz[N]; // lk initialized to i, sz initialized to 1
vvi idxs_of_div(N);
vi divs;

vi factors(int n) {
	vi fax;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0) {
			if(i == sqrt(n)) fax.pb(i);
			else fax.pb(i), fax.pb(n / i);
		}
	return fax;
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
		
		int t, n, m, i, j, u, v;

		cin >> t;

		for(int T = 1; T <= t; T++) {

			int ans = 0;

			REP(i, N) c[i] = 0;
			for(auto it : divs) idxs_of_div[it].clear();
			divs.clear();

			cin >> n;
			FOR(i, 1, n) cin >> a[i];
			REP(i, n + 1) lk[i] = i, sz[i] = 1;

			FOR(i, 1, n) {
				vi fx = factors(a[i]);
				for(auto it : fx) {
					idxs_of_div[it].pb(i);
					if(!c[it]) divs.pb(it);
					c[it] = 1;
				}
			}

			sort(divs.begin(), divs.end(), greater <int>());
			// for(auto it : divs) cout << it << " "; cout << endl;

			for(auto it : divs) {
				int num = 0;
				REP(j, idxs_of_div[it].size())
					if(!same(idxs_of_div[it][0], idxs_of_div[it][j])) {
						unite(idxs_of_div[it][0], idxs_of_div[it][j]);
						// cout << idxs_of_div[it][0] << " " << idxs_of_div[it][j] << endl;
						num++;
					}
				ans += num * it;
			}

			cout << "Case #" << T << ": " << ans << endl;
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
