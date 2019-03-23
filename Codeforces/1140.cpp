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

struct song {
	int l, c;
};
 
bool cmp(song a, song b) {
	if(a.c == b.c) return a.l < b.l;
	return a.c < b.c;
}

const int N = 300007;

song p[N];
int n, m, ans, dp[N];

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
			
		int n, m, i, j, u, v, ans = 0;

		cin >> n >> m;

		for(i = 0; i < n; i++)
			cin >> p[i].l >> p[i].c;

		sort(p, p + n, cmp);

		priority_queue <int, vi, greater <int> > pq;

		for(i = n - 1; i >= 0; i--) {
			if(i == n - 1) {
				dp[i] = p[i].l;
				pq.p(p[i].l);
			}
			else if(i >= n - m) {
				dp[i] = dp[i + 1] + p[i].l;
				pq.p(p[i].l);
			}
			else {
				int fuck_this = pq.top();
				if(fuck_this < p[i].l) {
					pq.pop(); pq.p(p[i].l);
					dp[i] = dp[i + 1] - fuck_this + p[i].l;
				}
				else dp[i] = dp[i + 1];
			}
		}

		for(i = 0; i < n; i++) ans = max(ans, dp[i] * p[i].c);
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
	9. Matrix Exponentiation - matrix
	10. Merge Sort Tree - mstree
	11. Modular Inverse - modinv
	12. Range Segment Tree (w/ Lazy) - segtree
	13. Range Segment Tree (w/out Lazy) - rstree
	14. Sieve of Eratosthenes - sieve
*/
