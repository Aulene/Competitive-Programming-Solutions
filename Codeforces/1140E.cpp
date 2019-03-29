#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define ld long double
#define int long long int
#define mod 998244353
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

const int N = 7;

vvi vs(N);

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
		
		int n, m, i, j, u, v, ans = 1;
		// int M = 2e5;

		// v = (M) * (M - 1) * (M - 1) % mod;
		cout << v << endl;

		cin >> n >> m;

		for(i = 1; i <= n; i++) {
			cin >> u;
			vs[i & 1].pb(u);
		}

		// for(i = 0; i < 2; i++) {
		// 	for(auto it : vs[i]) cout << it << " "; cout << endl;
		// }

		for(i = 0; i < 2; i++) {
			int lst = 0;

			for(j = 0; j < vs[i].size(); j++) {
				
				int pos = 1;
				int ini = (vs[i][j] == -1) ? 1 : 0;

				while(j < vs[i].size() && vs[i][j] == -1) {
					
					if(j == 0) {
						// cout << "f" << endl;
						if((j + 1 < (int) vs[i].size()) && vs[i][j + 1] != -1) pos *= m - 1;
						else pos *= m;
					}
					else if(vs[i][j - 1] == -1 && (j + 1 < (int) vs[i].size()) && vs[i][j + 1] == -1) 
						pos *= m - 1;
					else if(vs[i][j - 1] != -1 && (j + 1 < (int) vs[i].size()) && vs[i][j + 1] == -1) 
						pos *= m - 1;
					else if(vs[i][j - 1] != -1 && (j + 1 < (int) vs[i].size()) && vs[i][j + 1] != -1) {
						set <int> sx;
						sx.insert(vs[i][j - 1]); sx.insert(vs[i][j + 1]);
						pos *= ((int) m - sx.size());
					}
					else if(j + 1 == ((int) vs[i].size()))
						pos *= m - 1;

					// printf("i: %lld j: %lld ans: %lld pos: %lld\n", i, j, ans, pos);
					pos %= mod;
					j++;
				}

				if(ini) j--;

				ans = (ans * pos) % mod;
			}
		}

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
