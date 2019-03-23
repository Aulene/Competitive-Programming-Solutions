#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ld long double
#define int long long int
#define mod 1000000007
#define p push
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define vi vector <int> 
#define vvi vector < vector <int> > 
#define pi pair <int, int> 
#define ppi pair < pair <int, int>, int>
#define vpi vector < pi >
#define vppi vector < ppi >
#define vvpi vector < vector < pi > > 
#define msi multiset <int> 
#define si set <int>
#define zp mp(0, 0)

/*
	Easy mistakes to spot before submitting!
	1. Check const int N (1e5, 2e5).
	2. Check easy cases (n = 1, 2).
	3. Overflows! You'll fuck this up when binary searching.
	4. LONG LONGS! Alternatively, remove the int long long int sometimes.
	5. Check if you're dividing by 0 somewhere.
	6. Memory allocations, sometimes the vector is N^2.
*/

#define mid (start + end) / 2

const int N = 100007;
const int M = 32;

int lazy[4 * N], a[N];
vi empv(M, 0);

struct RSTree
{
	vi val;
	RSTree *l, *r;

	RSTree() : val(M, 0) {};

	vi merge(vi a, vi b) { 
		vi ret(M);
		for(int i = 0; i < M; i++) ret[i] = a[i] + b[i];
		return ret;
	}

	RSTree *build(int start, int end)
		{
			if(start == end) {
				for(int i = 0; i < M; i++) 
					if(a[start] & (1 << i)) val[i] = 1;
			}
			else
				{
					l = new RSTree, r = new RSTree;
					l = l -> build(start, mid), r = r -> build(mid + 1, end);
					val = merge(l -> val, r -> val);
				}
			return this;
		}

	RSTree *update(int lazy[], int start, int end, int a, int b, int v, int level = 1)	
		{
			if(lazy[level] != 0) {

				for(int i = 0; i < M; i++)
					if(lazy[level] & (1 << i)) val[i] = (end - start + 1 - val[i]);

				if(start != end) {
					lazy[2 * level] ^= lazy[level];
					lazy[2 * level + 1] ^= lazy[level];
				}

				lazy[level] = 0;
			}

			if(start > b || end < a)
				return this;

			if(start >= a && end <= b) {

				for(int i = 0; i < M; i++)
					if(v & (1 << i)) val[i] = (end - start + 1 - val[i]);

				if(start != end) {
					lazy[2 * level] ^= v;
					lazy[2 * level + 1] ^= v;
				}			

				return this;
			}

			l = l -> update(lazy, start, mid, a, b, v, 2 * level);
			r = r -> update(lazy, mid + 1, end, a, b, v, 2 * level + 1);
			val = merge(l -> val, r -> val);

			return this;
		}

	vi query(int lazy[], int start, int end, int a, int b, int level = 1)
		{
			if(lazy[level] != 0) {	

				for(int i = 0; i < M; i++)
					if(lazy[level] & (1 << i)) val[i] = (end - start + 1 - val[i]);

				if(start != end) {
					lazy[2 * level] ^= lazy[level];
					lazy[2 * level + 1] ^= lazy[level];
				}

				lazy[level] = 0;
			}

			if(start > b || end < a)
				return empv;
			else if(start >= a && end <= b)
				return val;
			else
				return merge(l -> query(lazy, start, mid, a, b, 2 * level), r -> query(lazy, mid + 1, end, a, b, 2 * level + 1));
		}
};

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
		
		int n, m, i, j, u, v, q, l, r, x;

		cin >> n;

		for(i = 1; i <= n; i++) cin >> a[i];

		RSTree *root = new RSTree;
		root = root -> build(1, n);

		cin >> m;

		while(m--) {
			cin >> q;

			if(q == 1) {
				cin >> l >> r;

				int ans = 0;

				vi ansv = root -> query(lazy, 1, n, l, r);
				
				// for(int i = 0; i < ansv.size(); i++) 
				// 	cout << i << " " << ansv[i] << endl;

				for(int i = 0; i < ansv.size(); i++) 
					ans += (1 << i) * ansv[i];

				cout << ans << endl;
			}
			else {
				cin >> l >> r >> x;
				root = root -> update(lazy, 1, n, l, r, x);
			}
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
	9. Matrix Exponentiation - matrix
	10. Merge Sort Tree - mstree
	11. Modular Inverse - modinv
	12. Range Segment Tree (w/ Lazy) - segtree
	13. Range Segment Tree (w/out Lazy) - rstree
	14. Sieve of Eratosthenes - sieve
*/
