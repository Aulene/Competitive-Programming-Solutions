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

int solve(string s, int n) {
	if(s[0] == '>' || s[n - 1] == '<' || n == 1) return 0;

	int fl = -1, fr = -1;

	for(int i = 0; i < n; i++)
		if(s[i] == '>') {
			fr = i;
			break;
		}

	for(int i = n - 1; i >= 0; i--)
		if(s[i] == '<') {
			fl = i;
			break;
		}

	if(fl == -1 || fr == -1) return 0;

	return min(fr, n - fl - 1);
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
		
		int t, n, i, j, u, v;
		string s;

		cin >> t;

		while(t--) {
			cin >> n >> s;
			cout << solve(s, n) << endl;
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