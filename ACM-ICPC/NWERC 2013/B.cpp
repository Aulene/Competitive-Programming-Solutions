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

const int N = 1007;

int a[N], mx[N][N];
vvi vs(N);

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

			if((scanf("%d%d", &n, &m)) != 2) { return 0; }
			
			REP(i, N)
				REP(j, N) mx[i][j] = 0;
			REP(i, N) vs[i].clear();

			int ans = 0;

			FOR(i, 1, n + 1) cin >> a[i];

			REP(i, m) {
				cin >> u >> v;
				vs[u].pb(v); vs[v].pb(u);
				mx[u][v] = mx[v][u] = 1;
				ans = max(ans, a[u] + a[v]);
			}

			FOR(i, 1, n + 1) sort(all(vs[i]));

			FOR(i, 1, n + 1) {
				REP(j, vs[i].size()) {
					FOR(k, j + 1, vs[i].size()) {
						int x = i, y = vs[i][j], z = vs[i][k];
						if(mx[y][z]) ans = max(ans, a[x] + a[y] + a[z]);
						else continue;
						vi fours, fuck;
						set_intersection(all(vs[x]), all(vs[y]), back_inserter(fours));
						set_intersection(all(fours), all(vs[z]), back_inserter(fuck));
						for(auto it : fuck) ans = max(ans, a[x] + a[y] + a[z] + a[it]);
					}
				}
			}

			cout << ans << endl;
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
