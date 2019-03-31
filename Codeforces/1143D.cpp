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

vi pos_starts;
map <int, int> vis;

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

map <int, int> pos2;

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
		int min_ans = LLONG_MAX, max_ans = 0;
		

		// cout << CLOCKS_PER_SEC << endl;

		cin >> n >> m >> u >> v;

		int f = n * m;

		for(i = 0; i <= n * m - 1; i += m) {
			int l = (i - u + n * m) % (n * m);
			int r = (i + u + n * m) % (n * m);

			// cout << i << " " << l << " " << r << endl;

			if(!vis[l]) pos_starts.pb(l); vis[l] = 1;
			if(!vis[r]) pos_starts.pb(r); vis[r] = 1;
		}

		for(i = 0; i <= n * m - 1; i += m) {
			int l = (i - v + n * m) % (n * m);
			int r = (i + v + n * m) % (n * m);
			pos2[l] = 1; pos2[r] = 1;
		}

		shuffle(pos_starts.begin(), pos_starts.end(), rng);
		// for(auto it : pos_starts) cout << it << endl;

		cout << f << endl;

		while(clock() < 1.9 * CLOCKS_PER_SEC) {
			int idx = rng() % pos_starts.size();
			int st = pos_starts[idx];
			int l = rng() % f + 1;

			int ds = n * m - st;
			int flcm = lcm(ds, l);

			// cout << st << endl;
			// cout << ds << " " << l << " " << flcm << endl;
			
			// int cl1 = (st + l) / m;
			// int cl2 = (st + 2 * l) / m;

			// int p1 = abs(m * cl1 - (st + l));
			// int p2 = abs(m * cl2 - (st + l));
			// int dist = min(p1, p2);

			if(pos2[st + l]) {
				int x = flcm / l;
				min_ans = min(min_ans, x);
				max_ans = max(max_ans, x);
			}
		}

		cout << min_ans << " " << max_ans << endl;

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
