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

const int N = 100007;

vpi ansv(N, {0, 0});
vvi g(N);
int num = 1;

void dfs(int idx, int p = -1, int pedge = 0) {
	
	// cout << idx << endl;

	if(p == -1)  {
		ansv[idx].f = num++;	
		ansv[idx].s = num++;

		int used = 0;

		for(auto it : g[idx]) {
			if(!used) dfs(it, idx, ansv[idx].f), used = 1;
			else dfs(it, idx, ansv[idx].s);
		}
	}
	else {
		if(g[idx].size() - 1 == 0) {
			ansv[idx].f = ansv[p].f;
			ansv[idx].s = ansv[p].s;
		}
		else {
			ansv[idx].f = pedge;
			ansv[idx].s = num++;

			for(auto it : g[idx])
				if(it != p) dfs(it, idx, ansv[idx].s);
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
			
		int n, m, i, j, u, v;

		cin >> n;

		for(i = 0; i < n - 1; i++) {
			cin >> u >> v;
			g[u].pb(v); g[v].pb(u);
		}
			
		dfs(1);

		for(int i = 1; i <= n; i++) cout << ansv[i].f << " " << ansv[i].s << endl;

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
