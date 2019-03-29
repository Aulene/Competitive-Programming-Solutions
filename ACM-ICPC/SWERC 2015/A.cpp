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

const int N = 5007;
vvi g(N), g2(N);

int n;
int num_low[N], num_high[N], vis[N];

void init() {
	for(int i = 0; i < N; i++) vis[i] = 0; 
}

int cnt_low(int idx) {
	int num = 0;
	vis[idx] = 1;
	for(auto it : g[idx])
		if(!vis[it]) num += 1 + cnt_low(it);
	return num;
}

int cnt_low2(int idx) {
	int num = 0;
	vis[idx] = 1;
	for(auto it : g2[idx])
		if(!vis[it]) num += 1 + cnt_low2(it);
	return num;
}


signed main()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cout.tie(NULL);
		
		// ifstream cin ("/Users/Aulene\ 1/Desktop/input.txt");
		// ofstream cout ("/Users/Aulene\ 1/Desktop/output.txt");

		// ifstream cin ("input.txt");
		// ofstream cout ("output.txt");
		
		// ifstream cin ("usaco.in");
		// ofstream cout ("usaco.out");
		
		int l, r, m, i, j, u, v;

		cin >> l >> r >> n >> m;

		for(i = 0; i < m; i++) {
			cin >> u >> v;
			g[u].pb(v);
			g2[v].pb(u);
		}
		
		// cnt_low(1);

		for(i = 0; i < n; i++) {
			init();
			num_low[i] = cnt_low(i);
			num_high[i] = cnt_low2(i);
		}

		int ans1 = 0, ans2 = 0, ans3 = 0;
		
		for(i = 0; i < n; i++)
			if(n - num_low[i] <= l) ans1++;
		for(i = 0; i < n; i++)
			if(n - num_low[i] <= r) ans2++;
		for(i = 0; i < n; i++)
			if(num_high[i] >= r) ans3++;

		cout << ans1 << endl << ans2 << endl << ans3 << endl;

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
