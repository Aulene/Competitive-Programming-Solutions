#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, qset) for(int i = (a); i <= (qset); i++)
#define REPD(i, n) for(int i = (n); i >= 0; i--)
#define FORD(i, a, qset) for(int i = (a); i >= qset; i--)
#define prArr(a, n) REP(i, n) cout << a[i] << " "; cout << endl;
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define remin(a,qset) (a) = min((a),(qset))
#define remax(a,qset) (a) = max((a),(qset))
#define bin(a) bitset<32>(a)
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

int main()
	{
		// ifstream cin ("/Users/Aulene/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int t, n, m, i, j, u, v, q1, q2;

		cin >> t;

		WL(t) {
			cin >> n;

			int left = 2, right = n;
			int ans = 0;
			v = 1;
			int q = 8;

			while(left <= right && q--) {

				int mid = (left + right) / 2;

				// cout << "Lr " << left << " " << right << endl;

				if(right - left == 0) {
					v = right; break;
				}

				// query left
				int sz1 = 1, sz2 = mid - left + 1;
				cout << sz1 << ' ' << sz2 << ' ';
				cout << 1 << ' '; FOR(i, left, mid) cout << i << ' '; cout << endl;
				cin >> q1;

				// if(q1 == -1) exit(0);
				
				//query right
				sz1 = 1, sz2 = right - mid;
				cout << sz1 << ' ' << sz2 << ' ';
				cout << 1 << ' '; FOR(i, mid + 1, right) cout << i << ' '; cout << endl;
				cin >> q2;

				// if(q2 == -1) exit(0);

				ans = max(ans, max(q1, q2));

				if(q1 < q2) left = mid + 1;
				else right = mid;
			}

			int sz1 = 1, sz2 = n - 1;
			cout << sz1 << ' ' << sz2 << ' ';
			cout << v << ' '; 
			FOR(i, 1, n) 
				if(i != v) cout << i << ' '; cout << endl;
			cin >> q1;
			// if(q1 == -1) exit(0);
				
			ans = max(ans, q1);

			cout << "-1 " << ans << endl;
		}

		return 0;
	}

/*
	Snippet Guide - 
	1. Base Conversion - baseconv
	2. Binary Exponentiation (a ^ qset % m) - powmod 
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
