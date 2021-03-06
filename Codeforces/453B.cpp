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
#define bin(a) bitset<8>(a)
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

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

/*
	Easy mistakes to spot before submitting!
	1. Check const int N (1e5, 2e5).
	2. Check easy cases (n = 1, 2).
	3. Overflows! You'll fuck this up when binary searching.
	4. LONG LONGS! Alternatively, remove the int long long int sometimes.
	5. Check if you're dividing by 0 somewhere.
	6. Memory allocations, sometimes the vector is N^2.
*/

const int N = 107;
const int M = 67;
const int K = 100007;

int a[N], dp[N][K], p_sets[N];
bool ip[M];
vi prime_facts;

vi factors(int n) {
	vi fax;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0) {
			if(i == sqrt(n)) fax.pb(i);
			else fax.pb(i), fax.pb(n / i);
		}
	sort(fax.begin(), fax.end());
	return fax;
}

vi get_prime_facts(int n) {
	vi ansv;
	FOR(i, 1, 60)
		if(ip[i] && (n % i == 0)) ansv.pb(i);
	return ansv;
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

		cin >> n;
		FOR(i, 1, n) cin >> a[i];

		REP(i, M - 1)
			if(factors(i).size() == 2) prime_facts.pb(i), ip[i] = 1;

		cout << prime_facts.size() << endl;

		FOR(i, 1, N - 1) {
			int prime_set = 0;
			REP(j, prime_facts.size())
				if(i % prime_facts[j] == 0) prime_set = prime_set | (1 << j);
			p_sets[i] = prime_set;
			cout << i << "\t" << bin(prime_set) << "\t" << prime_set << endl;
		}

		FOR(i, 1, N - 1)
			FOR(j, 1, K - 1) dp[i][j] = INT_MAX;

		FOR(i, 1, n)
			FOR(j, 1, 60) {
				int cur_pset = p_sets[j];
				//iwanttofuckingkillmyself
				//whatinthegoodfuckisthiscode
				FOR(k, 1, K - 1)
					if((cur_pset & k) == 0) {
						int new_pset = cur_pset | k;
						if(k < 10) {
							printf("j = %d DP{%d, %d} = min(%d, %d)\n", j, i, new_pset, dp[i][new_pset], abs(a[i] - j) + dp[i - 1][k]);
							cout << "cur_pset = " << bin(cur_pset) << " prev_pset = " << bin(k) << endl;
						}
						dp[i][new_pset] = min(dp[i][new_pset], abs(a[i] - j) + dp[i - 1][k]);
					}
			}

		int ans = INT_MAX;
		FOR(i, 1, K - 1) ans = min(ans, dp[n][i]);

		cout << ans << endl;

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
