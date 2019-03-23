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

const int N = 200007;

int phi[N], pre_phi[N];
int num[N], denom[N];
int m_minus_1_to_k[N], m_only_to_k[N], num_m[N];

void euler() {
	for(int i = 1; i < N; ++i) {
		phi[i] += i;
		for (int j = 2 * i; j < N; j += i)
			phi[j] -= phi[i];
	}
	for(int i = 1; i < N; i++)
		pre_phi[i] = pre_phi[i - 1] + phi[i];
}

int inv(int a, int m) { return a < 2 ? a : ((1 - m * 1ll * inv(m % a, a)) / a % m + m) % m; }

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
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
		
		euler();

		int n, m, i, j, u, v;
		int ans = 0;

		cin >> m;

		num[1] = 1;
		denom[1] = m;
		m_minus_1_to_k[0] = 1;
		m_only_to_k[0] = 1;
		num_m[0] = 0;

		for(i = 1; i < N; i++) {
			m_minus_1_to_k[i] = (m_minus_1_to_k[i - 1] * (m - 1)) % mod;
			m_only_to_k[i] = (m_only_to_k[i - 1] * m) % mod;
			num_m[i] = (m_only_to_k[i] - m_minus_1_to_k[i] + mod) % mod;
		}

		// for(i = 1; i <= 5; i++) cout << m_only_to_k[i] << " "; cout << endl;

		// pre_phi[m]--;
		
		cout << pre_phi[m] << endl;

		for(i = 2; i < N; i++) {
			int prev_num = (denom[i - 1] - num[i - 1] + mod) % mod;

			// if(i < 10) cout << i << "  " << prev_num << endl;

			// if(i < 10) printf("num: p: %lld num_m: %lld\n", prev_num, num_m[i - 1]);

			num[i] = ((prev_num * num_m[i - 1]) % mod * pre_phi[m]) % mod;
			denom[i] = (denom[i - 1] * m_only_to_k[i]) % mod;

			int div = gcd(num[i], denom[i]);
			num[i] /= div; denom[i] /= div; 
		}

		for(i = 1; i <= 10; i++) {
			cout << num[i] << " " << denom[i] << endl;
		}

		for(i = 1; i <= m; i++) {
			int prob = (num[i] * inv(denom[i], mod)) % mod;
			int cur = (prob * i) % mod;
			ans = (ans + cur) % mod;
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
