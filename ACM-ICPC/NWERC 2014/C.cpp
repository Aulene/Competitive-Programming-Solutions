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

const int N = 2007;
const int M = 27;

int a[N], p[N], dp[N][M];
int c[N][N];

int compute(int cost) {
	int rem = cost % 10;
	if(rem >= 5) return cost + (10 - rem);
	return cost - rem;
}

void init() {
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++) dp[i][j] = INT_MAX;
	dp[0][0] = 0;
}

signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene/Desktop/18-nogain.in");
		// ofstream cout ("/Users/Aulene/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		init();

		// cout << INT_MAX << endl;

		int n, m, i, j, k, u, v, ans = LLONG_MAX;

		cin >> n >> m;
		m = min(n, m);

		for(i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
		
		for(i = 1; i <= n; i++)
			for(j = i; j <= n; j++) c[i][j] = compute(p[j] - p[i - 1]);
		for(i = 1; i <= n; i++) c[0][i] = compute(p[i]);

		// for(i = 1; i <= n; i++) {
		// 	for(j = 1; j <= n; j++) cout << c[i][j] << " "; cout << endl;
		// }

		for(i = 1; i <= m; i++) {
			for(j = 1; j <= n; j++) {
				for(k = 0; k <= j; k++)
					dp[j][i] = min(dp[j][i], dp[k - 1][i - 1] + c[k][j]);
			}
		}

		// for(i = 0; i <= m; i++) {
		// 	for(j = 1; j <= n; j++) cout << dp[j][i] << " "; cout << endl;
		// }

		for(i = 1; i <= n; i++)
			ans = min(ans, dp[i][m] + c[i + 1][n]);

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
