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

ld compute(int n, ld p, ld s, ld v, ld c) {

	ld log_n = (ld) log2(n);
	ld pv = (ld) c * sqrt(2.0);
	ld log_p = (ld) pow(log_n, pv);

	ld time = (ld) n * log_p / ((ld) p * 1e9);
	time += (ld) ((c + 1) * s) / (c * v);

	return time;
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
			
		int n, m, i, j, u;
		ld p, s, v;
		ld ans1, ans2;

		cin >> n >> p >> s >> v;

		ld start = 0.0001, end = 100.0;
		int its = 200;

		while(its--) {

			ld cur_c1 = (ld) (start * 2.0 + end) / 3.0;
			ld cur_c2 = (ld) (start + 2.0 * end) / 3.0;

			ld val1 = compute(n, p, s, v, cur_c1);
			ld val2 = compute(n, p, s, v, cur_c2);

			// printf("%0.6Lf %0.6Lf\n", val1, val2);

			if(val1 < val2) {
				ans1 = cur_c2;
				ans2 = val1;
				end = cur_c2;
			}
			else start = cur_c1;
		}
		
		printf("%0.16Lf %0.16Lf\n", ans2, ans1);

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
