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

/*
	Easy mistakes to spot before submitting!
	1. Check const int N (1e5, 2e5).
	2. Check easy cases (n = 1, 2).
	3. Overflows! You'll fuck this up when binary searching.
	4. LONG LONGS! Alternatively, remove the int long long int sometimes.
	5. Check if you're dividing by 0 somewhere.
	6. Memory allocations, sometimes the vector is N^2.
*/

const int N = 23;
const int M = 1200007;

map <string, int> mx;
map < pi, int> mx2;
vppi vs;

int poke[N];
int d[N][N];
int dp[N][M]; // min cost of catching bitmask(M) pokes till town j

int tot_poke = 1;
int num_towns = 1;

void recur(int idx, int mask) {
	FOR(i, 0, num_towns - 1) {
		int new_mask = mask | poke[i];
		if(dp[i][new_mask] > d[idx][i] + dp[idx][mask]) {
			dp[i][new_mask] = d[idx][i] + dp[idx][mask];
			recur(i, new_mask);
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
			
		REP(i, N) REP(j, M) dp[i][j] = INT_MAX;
		dp[0][0] = 0;

		int n, m, i, j, u, v;
		string s;

		cin >> n;

		vs.pb({{0, 0}, 0});

		REP(i, n) {
			cin >> u >> v >> s;
			
			if(mx[s] == 0) mx[s] = tot_poke++;
			if(mx2[{u, v}] == 0) mx2[{u, v}] = num_towns++;

			poke[mx2[{u, v}]] = poke[mx2[{u, v}]] | (1 << mx[s]); 
			vs.pb({{u, v}, mx[s]});
		}

		FOR(i, 0, num_towns - 1)
		FOR(j, 0, num_towns - 1) d[i][j] = abs((vs[i].F.F - vs[j].F.F) + (vs[i].F.S - vs[j].F.S));

		FOR(i, 1, num_towns - 1) poke[i] = poke[i] >> 1;
		// FOR(i, 1, num_towns - 1) cout << bin(poke[i]) << endl;

		// FOR(i, 1, num_towns - 1) {
		// 	FOR(j, 1, num_towns - 1) cout << d[i][j] << " "; cout << endl;
		// } cout << endl;

		recur(0, 0);

		int f_mask = (1 << (tot_poke - 1)) - 1;
		int ans = INT_MAX;

		// FOR(i, 1, num_towns - 1) {
		// 	FOR(j, 0, f_mask) 
		// 		if(dp[i][j] != INT_MAX) 
		// 			cout << i << " " << bin(j) << " " << dp[i][j] << endl; 
		// 		cout << endl;
		// }

		cout << dp[0][f_mask] << endl;

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
