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
		int a, b, x;

		cin >> a >> b >> x;

		deque <int> dq;

		if(x == 2) {
			if(a == 1 && b == 2) {
				cout << "101" << endl; return 0;
			}
			else if(a == 2 && b == 1) {
				cout << "010" << endl; return 0;
			}

			if(b > a) {
				while(a) dq.push_back(0), a--;
				dq.push_front(1);
				dq.push_back(1);
				b -= 2;
				while(b > 0) dq.push_back(1), b--;
			}
			else {
				while(b) dq.push_back(1), b--;
				dq.push_front(0);
				dq.push_back(0);
				a -= 2;
				while(a > 0) dq.push_back(0), a--;
			}
			while(!dq.empty()) cout << dq.front(), dq.pop_front();
			return 0;
		}

		dq.push_back(1);
		dq.push_back(0);
		a--, b--, x--;

		while(x) {
			if(a) {
				if(dq.back() == 1) dq.push_back(0), a--, x--;
				else if(dq.front() == 1) dq.push_front(0), a--, x--; 
			}

			if(!x) break;
			
			if(b) {
				if(dq.back() == 0) dq.push_back(1), b--, x--;
				else if(dq.front() == 0) dq.push_front(1), b--, x--; 
			}
		}

		while(b && dq.front() == 1) dq.push_front(1), b--;
		while(b && dq.back() == 1) dq.push_back(1), b--;
		while(a && dq.front() == 0) dq.push_front(0), a--;
		while(a && dq.back() == 0) dq.push_back(0), a--;
		
		while(!dq.empty()) cout << dq.front(), dq.pop_front();
		

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
