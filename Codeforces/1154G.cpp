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
#define bin(a) bitset<32>(a)
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

const int N = 1000007;
const int M = 10000007;
int fd[M];
vpi divs[M];
vpi vs;

vi factors(int n) {
	vi fax;
	for(int i = 1; i <= sqrt(n); i++)
		if(n % i == 0) {
			if(i == sqrt(n)) fax.pb(i);
			else fax.pb(i), fax.pb(n / i);
		}
	// sort(fax.begin(), fax.end());
	return fax;
}

bool cmp(pi a, pi b) { return a.F < b.F; }

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
		
		int n, m, i, j, u, v, ans_lcm = LLONG_MAX, ans1, ans2;

		cin >> n;
		REP(i, n) {
			cin >> u;
			vs.pb({u, i});
		}
		sort(vs.begin(), vs.end(), cmp);

		REP(i, n) {
			if(fd[vs[i].F] == 2) continue;
			fd[vs[i].F]++;
			// cout << vs[i].F << endl;
			vi fx = factors(vs[i].F);
			// for(auto it : fx) cout << it << " "; cout << endl;
			for(auto it : fx) {
				if(divs[it].size() == 2) continue;
				divs[it].pb(vs[i]);
			}
		}

		// FOR(i, 1, 10) {
		// 	cout << i << endl;
		// 	for(auto it : divs[i]) cout << it.F << " " << it.S << endl; cout << endl;
		// }

		FOR(i, 1, M - 1) {
			if(divs[i].size() >= 2) {
				int f1 = divs[i][0].F;
				int f2 = divs[i][1].F;
				int mx = f1 * f2;
				mx = mx / i;

				if(mx < ans_lcm) {
					ans_lcm = mx;
					ans1 = divs[i][0].S;
					ans2 = divs[i][1].S;
				}
			}
		}

		if(ans1 > ans2) swap(ans1, ans2);

		cout << ans1 + 1 << " " << ans2 + 1 << endl;
 

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
