#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589793238462643383279502884197169399375105820974944;

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REPD(i, n) for(int i = (n); i >= 0; i--)
#define FORD(i, a, b) for(int i = (a); i >= b; i--)
#define all(v) v.begin(),v.end()
#define WL(t) while(t--)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define remin(a,b) (a) = min((a),(b))
#define remax(a,b) (a) = max((a),(b))
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
#define vpi vector < pi >
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

const int MAXN = 101;
const int mod = (int)1e9 + 7;

struct matrix {
    int N = MAXN; // N <= MAXN
    int a[MAXN][MAXN]; 
    
    matrix(){
        memset(a, 0, sizeof(a));
    }
    matrix(int n){
        N = n;
        memset(a, 0, sizeof(a));
    }
    decltype(a[0]) operator[](int x){
        return a[x];
    }
    static matrix I(int n){
        matrix m(n);
        for(int i = 0; i < n; i++) m[i][i] = 1;
        return m;
    }
    
    matrix friend operator*(matrix &a, matrix &b){
        matrix c;
        for(int i=0; i<a.N; i++){
            for(int j=0; j<a.N; j++){
                for(int k = 0; k<a.N; k++){
                    c[i][j] += 1ll * a[i][k] * b[k][j] % mod;
                    c[i][j] %= mod;
                }
            }
        }
        return c;
    }
    matrix friend operator^(matrix &a, int b){
        matrix ans = I(a.N);
        while(b){
            if(b%2!=0) ans = ans*a;
            a = a*a;
            b>>=1;
        }
        return ans;
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
		
		int n, i, j, u, v;

		cin >> n;

		matrix m(2), m2(2);
		m[0][0] = m[0][1] = m[1][0] = m[1][1] = 1;
		m2[0][0] = 1; m2[0][1] = 3;

		if(n == 2) cout << 1 << endl;
		else {
			n -= 2;
			m = m ^ n;

			for(i = 0; i < 2; i++) {
				for(j = 0; j < 2; j++) cout << m.a[i][j] << " "; cout << endl;
			}

			m2 = m2 * m;

			for(i = 0; i < 2; i++) cout << m2[0][i] << " "; cout << endl;
			
			cout << m2[0][1] << endl;
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
